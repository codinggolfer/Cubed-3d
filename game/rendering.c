/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:26:09 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/22 19:33:00 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_floor_ceiling(mlx_image_t *img, int x, t_draw *draw, t_game *game)
{
	int	y;

	if (draw->end < 0)
		return ;
	y = draw->end;
	while (y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(img, x, y, game->floor_colour);
		y++;
	}
	y = 0;
	while (y < draw->start)
	{
		mlx_put_pixel(img, x, y, game->ceiling_colour);
		y++;
	}
}

void calculate_texture_coords(t_game *game, t_ray *ray, t_draw draw, mlx_texture_t *texture)
{
	// Calculate wall_x (where exactly the wall was hit)
	if (ray->side == 0)
		game->wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		game->wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	game->wall_x -= floor(game->wall_x);
	
	// Calculate tex_x and adjust for direction
	game->tex_x = (int)(game->wall_x * texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		game->tex_x = texture->width - game->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		game->tex_x = texture->width - game->tex_x - 1;
	
	// Calculate step and initial tex_pos
	int line_height = draw.end - draw.start;
	game->step = (double)texture->height / line_height;
	game->tex_pos = (draw.start - SCREEN_HEIGHT / 2 + line_height / 2) * game->step;
}

static mlx_texture_t *select_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)  // Vertical wall hit
	{
		if (ray->ray_dir_x > 0)
			return (game->we_txt);
		return (game->ea_txt);
	}
	else  // Horizontal wall hit
	{
		if (ray->ray_dir_y > 0)
			return (game->so_txt);
		return (game->no_txt);
	}
}

void draw_textured_wall_slice(t_game *game, t_ray *ray, t_draw draw, int x)
{
	mlx_texture_t *texture;
	int y;
	uint32_t color;

	texture = select_wall_texture(game, ray);
	calculate_texture_coords(game, ray, draw, texture);
	
	y = draw.start;
	while (y < draw.end)
	{
		game->tex_y = (int)game->tex_pos & (texture->height - 1);
		game->tex_pos += game->step;
		color = *(uint32_t *)(texture->pixels + 
			(game->tex_y * texture->width + game->tex_x) * sizeof(uint32_t));
		mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}
