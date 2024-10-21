/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:14:45 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/21 11:37:20 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_step(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
}

void    perform_dda(t_ray *ray, char **map)
{
	//printf("y value: %i & x value: %i\n", ray->map_y, ray->map_x);
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x >= 1 && (size_t)ray->map_x < ft_strlen(map[0])
			&& ray->map_y >= 1 && ray->map_y < count_arg_array(map) - 1)
		{
    		if (map[ray->map_y][ray->map_x] == '1')
        		ray->hit = 1;
		}
		else
			ray->hit = 1;
	}
}

void    calculate_wall(t_ray *ray, t_player *player, int *draw_start, int *draw_end)
{
	int	line_height;

	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->pos_x
			+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->pos_y
			+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	*draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (*draw_end >= SCREEN_HEIGHT)
		*draw_end = SCREEN_HEIGHT - 1;
}

void	draw_vertical_line(mlx_image_t *img, int x, int start, int end, uint32_t color)
{
	int	y;

	y = start;
	while (y < end)
	{
		mlx_put_pixel(img, x, y, color);
		y++;
	}
}
void	draw_floor_ceiling(mlx_image_t *img, int x, int start, int end, t_game *game)
{
	int	y;

	if (end < 0)
		return ;
	y = end;
	while (y < SCREEN_HEIGHT)
	{
		mlx_put_pixel(img, x, y, game->floor_colour);
		y++;
	}
	y = 0;
	while (y < start)
	{
		mlx_put_pixel(img, x, y, game->ceiling_colour);
		y++;
	}
}

void    ray_casting(t_game *game)
{
	t_ray		ray;
	int			draw_start;
	int			draw_end;
	int			x;
	uint32_t	color;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(&ray, &game->player, x);
		calculate_step(&ray, &game->player);
		perform_dda(&ray, game->map);
		calculate_wall(&ray, &game->player, &draw_start, &draw_end);
		if (ray.side == 1)
			color = 0xFF0000FF;  // Red if side is 1
		else
			color = 0x00FF00FF;    // otherwise green
		draw_floor_ceiling(game->img, x, draw_start, draw_end, game);
		draw_vertical_line(game->img, x, draw_start, draw_end, color);
		x++;
	}
}

