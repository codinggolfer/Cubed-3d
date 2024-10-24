/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:39:07 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/24 17:39:45 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->img->ceiling = NULL;
	data->img->ea = NULL;
	data->img->floor = NULL;
	data->img->map = NULL;
	data->img->no = NULL;
	data->img->so = NULL;
	data->img->top = NULL;
	data->img->we = NULL;
	data->dup_flag = 0;
	data->dup_char = 0;
	data->nl_flag = 0;
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

void	load_textures(t_game *game, t_data *data)
{
	game->no_txt = mlx_load_png(data->img->no);
	game->so_txt = mlx_load_png(data->img->so);
	game->ea_txt = mlx_load_png(data->img->ea);
	game->we_txt = mlx_load_png(data->img->we);
	if (!game->no_txt || !game->so_txt)
		ft_error("Failed to load textures");
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
	game->wall_x = 0;
	game->tex_x = 0;
	game->tex_y = 0;
	game->tex_scale = 0;
	game->tex_pos = 0;
}
