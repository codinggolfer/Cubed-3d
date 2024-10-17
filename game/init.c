/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:39:07 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/17 17:27:30 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void find_player_start(t_game *game, t_data *data);
void set_initial_direction(t_player *player, char direction);



void	init_game(t_game *game, t_data *data)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_error("Failed to initialize MLX");
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img || mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
		ft_error("Failed to create or display image");
	find_player_start(game, data);
	game->map = data->img->map;
	 printf("Map initialized. First few characters: %.10s\n", game->map[0]);
}

void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

int	position_direction_wrapper(t_game *game, int x, int y, char c)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	set_initial_direction(&game->player, c);
	game->map[y][x] = '0';
	return (1);	//
}

/*
-adding .5 moves the player to the center of the grid cell
-We mark the position as empty after setting player
*/
void find_player_start(t_game *game, t_data *data)
{
	int	y;
	int x;
	int	player_found;

	player_found = 0;
	y = 0;
	while (data->img->map[y])
	{
		x = 0;
		while (data->img->map[y][x])
		{
			if (data->img->map[y][x] == 'N')
				player_found = position_direction_wrapper(game, x, y, 'N');
			else if (data->img->map[y][x] == 'S')
				player_found = position_direction_wrapper(game, x, y, 'S');
			else if (data->img->map[y][x] == 'W')
				player_found = position_direction_wrapper(game, x, y, 'W');
			else if (data->img->map[y][x] == 'E')
				player_found = position_direction_wrapper(game, x, y, 'E');
			if (player_found == 1)
				return ;
			x++;
		}
		y++;
	}
}

/*
.66 value represents the length of the plane vector, the raycasting loop goes 
from -1 to 1 across the screen width. This value is multiplied by the plane 
vector to get the ray direction. So .66 creates an FOV of about 66 degrees, 
which is close to a realistic human field of view for a computer screen
*/
void set_initial_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0; player->dir_y = -1;
		player->plane_x = 0.66; player->plane_y = 0;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0; player->dir_y = 1;
		player->plane_x = -0.66; player->plane_y = 0;
	}
	else if (direction == 'E')
	{
		player->dir_x = 1; player->dir_y = 0;
		player->plane_x = 0; player->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1; player->dir_y = 0;
		player->plane_x = 0; player->plane_y = -0.66;
	}
}



//STORAGE FOR OLD STUFF:
	// for (int y = 0; game->map[y]; y++)
	// {
	// 	for (int x = 0; game->map[y][x]; x++)
	// 	{
	// 		char c = game->map[y][x];
	// 		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	// 		{
	// 			game->player.posX = x + 0.5;
	// 			game->player.posY = y + 0.5;
	// 			set_initial_direction(&game->player, c);
	// 			game->map[y][x] = '0';
	// 			return;
	// 		}
	// 	}
	// }
	// ft_error("No valid player start position found in map");