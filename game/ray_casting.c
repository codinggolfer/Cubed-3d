/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:14:45 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/24 11:43:19 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_step(t_ray *ray, t_player *player)
{
	printf("Debug - Player position: pos_x=%f, pos_y=%f\n", player->pos_x, player->pos_y);
    printf("Debug - Ray map position: map_x=%d, map_y=%d\n", ray->map_x, ray->map_y);
    printf("Debug - Ray direction: ray_dir_x=%f, ray_dir_y=%f\n", ray->ray_dir_x, ray->ray_dir_y);
    printf("Debug - Delta distances: delta_x=%f, delta_y=%f\n", ray->delta_dist_x, ray->delta_dist_y);
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
		if (player->pos_y == ray->map_y + 1.0)  // If exactly on grid line
        {
            // Force it to check one grid cell in the direction we're looking
            ray->side_dist_y = ray->delta_dist_y * .000001;
        }
        else
        {
            ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
        }
		// ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
	printf("Debug - After calculation: side_dist_x=%f, side_dist_y=%f\n", 
           ray->side_dist_x, ray->side_dist_y);
    printf("Debug - Steps: step_x=%d, step_y=%d\n\n", ray->step_x, ray->step_y);
}

/*
** Digital Differential Analysis
** Finds which grid cell (map[x,y]) has a wall along the ray
*/
// void    perform_dda(t_ray *ray, char **map)
// {
// 	while (ray->hit == 0)
// 	{
// 		//   printf("Pre-step: side_dist_x=%f, side_dist_y=%f\n", 
//             //    ray->side_dist_x, ray->side_dist_y);
// 		if (ray->side_dist_x < ray->side_dist_y + .0001)
// 		{
// 			ray->side_dist_x += ray->delta_dist_x;
// 			ray->map_x += ray->step_x;
// 			ray->side = 0;
// 		}
// 		else
// 		{
// 			ray->side_dist_y += ray->delta_dist_y;
// 			ray->map_y += ray->step_y;
// 			ray->side = 1;
// 			//  printf("Stepped Y: new map_y=%d\n", ray->map_y);
// 		}
// 		if (ray->map_x >= 0 && (size_t)ray->map_x < ft_strlen(map[0])
// 			&& ray->map_y >= 0 && ray->map_y < count_arg_array(map))
// 		{
// 			if (map[ray->map_y][ray->map_x] == '1')
// 			{
// 				ray->hit = 1;
// 				   printf("Debug - Wall hit details:\n");
//    					 printf("  Position: map[%d][%d]\n", ray->map_y, ray->map_x);
//     					printf("  Side: %d\n", ray->side);
//     					printf("  Final side_dist_x: %f, side_dist_y: %f\n", 
//     				       ray->side_dist_x, ray->side_dist_y);
// 			}
// 		}
// 		else
// 			ray->hit = 1;
// 	}
// }
void    perform_dda(t_ray *ray, char **map)
{
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

        if (ray->map_x >= 0 && (size_t)ray->map_x < ft_strlen(map[0])
            && ray->map_y >= 0 && ray->map_y < count_arg_array(map))
        {
            if (map[ray->map_y][ray->map_x] == '1')
            {
                ray->hit = 1;
                // Special case: if we hit the back wall, force it to be a horizontal hit
                if (ray->map_y == count_arg_array(map) - 2)  // If this is the back wall
                    ray->side = 1;
            }
        }
        else
            ray->hit = 1;
    }
}

/*
** Calculates both the true height of the wall and its visible portion on screen
** First finds the perpendicular distance to the wall to avoid fisheye effect,
** then calculates the wall's true height in screen space (true_line_height).
** Finally, determines which portion of the wall is actually visible on screen 
** (draw->start to draw->end) and calculates any texture offset needed if wall
** exceeds screen bounds. The true height is saved for texture scaling,
** while the visible portion is used for actual rendering.
*/
void	calculate_wall(t_ray *ray, t_player *player, t_draw *draw)
{
	int	line_height;

	line_height = 0;
	// Calculate perpendicular wall distance
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->pos_x 
			+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->pos_y 
			+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
	// Calculate the true line height before any screen clamping
	line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	// Store the original height for texture scaling
	ray->true_line_height = line_height;
	// Calculate drawing bounds
	draw->start = -line_height / 2 + SCREEN_HEIGHT / 2;
	draw->end = line_height / 2 + SCREEN_HEIGHT / 2;
	// Calculate texture offset if wall exceeds screen height
	if (draw->start < 0)
	{
		draw->texture_offset = -draw->start;
		draw->start = 0;
	}
	else
		draw->texture_offset = 0;   
	if (draw->end >= SCREEN_HEIGHT)
		draw->end = SCREEN_HEIGHT - 1;
}

void    ray_casting(t_game *game)
{
	t_ray	ray;
	int		x;
	t_draw	draw;

	x = 0;
	draw.start = 0;
	draw.end = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(&ray, &game->player, x);
		calculate_step(&ray, &game->player);
		perform_dda(&ray, game->map);
		calculate_wall(&ray, &game->player, &draw);
		draw_textured_wall_slice(game, &ray, draw, x);
		draw_floor_ceiling(game->img, x, &draw, game);
		x++;
	}
}
