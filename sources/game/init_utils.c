/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:50:37 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/24 17:39:42 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** takes a char** representing RGB values and converts them into a single 
** integer that represents the color
*/
int	create_trgb(char **floor)
{
	int	tmp;

	tmp = 0;
	tmp = ft_atoi(floor[0]) << 16;
	tmp += ft_atoi(floor[1]) << 8;
	tmp += ft_atoi(floor[2]);
	return (tmp);
}

/*
** .66 value represents the length of the plane vector, the raycasting loop 
** goes from -1 to 1 across the screen width. This value is multiplied by the 
** plane vector to get the ray direction. So .66 creates an FOV of about 66 
** degrees, which is close to a realistic human field of view 
*/
void	set_initial_direction2(t_player *player, char direction)
{
	if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void	set_initial_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (direction == 'E')
		set_initial_direction2(player, direction);
	else if (direction == 'W')
		set_initial_direction2(player, direction);
}

/*
** Adding .5 to the player to put them in the center of the grid cell
** We mark the position as empty after setting player
*/
int	position_direction_wrapper(t_game *game, int x, int y, char c)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	game->map[y][x] = '0';
	set_initial_direction(&game->player, c);
	return (1);
}

void	find_player_start(t_game *game, t_data *data)
{
	int	y;
	int	x;
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
