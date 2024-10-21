/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:39:07 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/21 14:27:34 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

/*.66 value represents the length of the plane vector, the raycasting loop goes
from -1 to 1 across the screen width. This value is multiplied by the plane 
vector to get the ray direction. So .66 creates an FOV of about 66 degrees, 
which is close to a realistic human field of view for a computer screen */
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

void set_initial_direction(t_player *player, char direction)
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

// adding .5 moves the player to the center of the grid cell
// We mark the position as empty after setting player
int	position_direction_wrapper(t_game *game, int x, int y, char c)
{
	game->player.pos_x = x + 0.5;
	game->player.pos_y = y + 0.5;
	game->map[y][x] = '0';
	set_initial_direction(&game->player, c);
	return (1);
}

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

//takes a char** representing RGB values and converts 
//them into a single integer that represents the color
int create_trgb(char **floor)
{
	int tmp;

	tmp = 0;
	tmp = ft_atoi(floor[0]) << 16;
	tmp += ft_atoi(floor[1]) << 8;
	tmp += ft_atoi(floor[2]);
	return (tmp);
}

void	load_textures(t_game *game, t_data *data)
{
	game->no_txt = mlx_load_png(data->img->no);
	game->so_txt = mlx_load_png(data->img->so);
	if (!game->no_txt || !game->so_txt)
		ft_error("Failed to load textures");
	game->no_img = mlx_texture_to_image(game->mlx, game->no_txt);
	game->so_img = mlx_texture_to_image(game->mlx, game->so_txt);
	if (!game->no_img || !game->so_img)
		ft_error("Failed to create wall images");
	// mlx_delete_texture(game->no_txt);
	// mlx_delete_texture(game->so_txt);
}

void	init_game(t_game *game, t_data *data)
{
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_error("Failed to initialize MLX");
	load_textures(game, data);
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img || mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
		ft_error("Failed to create or display image");
	game->map = data->img->map;
	find_player_start(game, data);
	game->floor_rgb = ft_split(data->img->floor, ',');
	game->ceiling_rgb = ft_split(data->img->ceiling, ',');
	game->floor_colour = create_trgb(game->floor_rgb);
	game->ceiling_colour = create_trgb(game->ceiling_rgb);
	free_2darray(game->floor_rgb);
	free_2darray(game->ceiling_rgb);
	printf("Map initialized. First few characters: %.10s\n", game->map[0]);
}
