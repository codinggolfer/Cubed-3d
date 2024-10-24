/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:26:09 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/24 17:34:24 by aneitenb         ###   ########.fr       */
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

/*
** Handles the texture mapping calculations for each vertical slice of wall.
** First calculates the exact hit point on the wall (wall_x) and converts it
** to a texture x-coordinate, adjusting for wall orientation/direction.
** Then determines how to scale and position the texture using the wall's 
** true height to maintain proper proportions even at close distances.
** The step value controls texture scaling, while tex_pos determines where to
** start the texture when walls extend beyond the screen.
*/
void	calculate_texture_coords(t_game *game, t_ray *ray, t_draw draw,
	mlx_texture_t *texture)
{
	if (ray->side == 0)
		game->wall_x = game->player.pos_y + ray->perp_wall_dist * \
		ray->ray_dir_y;
	else
		game->wall_x = game->player.pos_x + ray->perp_wall_dist * \
		ray->ray_dir_x;
	game->wall_x -= floor(game->wall_x);
	game->tex_x = (int)(game->wall_x * texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		game->tex_x = texture->width - game->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		game->tex_x = texture->width - game->tex_x - 1;
	game->tex_scale = (double)texture->height / ray->true_line_height;
	game->tex_pos = (draw.texture_offset) * game->tex_scale;
}

static mlx_texture_t	*select_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (game->we_txt);
		return (game->ea_txt);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (game->so_txt);
		return (game->no_txt);
	}
}

void	draw_textured_wall_slice(t_game *game, t_ray *ray, t_draw draw, int x)
{
	mlx_texture_t	*texture;
	uint32_t		color;
	uint8_t			*pixel;
	int				y;

	texture = select_wall_texture(game, ray);
	calculate_texture_coords(game, ray, draw, texture);
	y = draw.start;
	while (y < draw.end)
	{
		game->tex_y = (int)game->tex_pos & (texture->height - 1);
		game->tex_pos += game->tex_scale;
		pixel = (uint8_t *)(texture->pixels + \
			(game->tex_y * texture->width + game->tex_x) * \
			texture->bytes_per_pixel);
		color = (pixel[0] << 24) | (pixel[1] << 16) | \
				(pixel[2] << 8) | (pixel[3]);
		mlx_put_pixel(game->img, x, y, color);
		y++;
	}
}
