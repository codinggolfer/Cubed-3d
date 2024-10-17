/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:39:07 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/17 13:21:39 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void find_player_start(t_game *game, t_data *data);
// void set_initial_direction(t_player *player, char direction);



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
}

void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->rayDirX = player->dirX + player->planeX * ray->cameraX;
	ray->rayDirY = player->dirY + player->planeY * ray->cameraX;
	ray->mapX = (int)player->posX;
	ray->mapY = (int)player->posY;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
}

int	position_direction_wrapper(t_game *game, int x, int y, char c)
{
	game->player.posX = x + 0.5;
	game->player.posY = y + 0.5;
	set_initial_direction(&game->player, c);
	game->map[y][x] = '0';
	return;
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
		player->dirX = 0; player->dirY = -1;
		player->planeX = 0.66; player->planeY = 0;
	}
	else if (direction == 'S')
	{
		player->dirX = 0; player->dirY = 1;
		player->planeX = -0.66; player->planeY = 0;
	}
	else if (direction == 'E')
	{
		player->dirX = 1; player->dirY = 0;
		player->planeX = 0; player->planeY = 0.66;
	}
	else if (direction == 'W')
	{
		player->dirX = -1; player->dirY = 0;
		player->planeX = 0; player->planeY = -0.66;
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