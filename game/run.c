/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:43:25 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/22 18:30:06 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_calls(void *param)
{
	t_game		*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("Game closed ESQ was pressed\n");
		mlx_close_window(game->mlx);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game, &game->player);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game, &game->player);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rot_right(&game->player);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rot_left(&game->player);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		strife_left(game, &game->player);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		strife_right(game, &game->player);
}

void game_loop(void* param)
{
	t_game *game = (t_game*)param;
	
	ray_casting(game);
}

void	run_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_loop_hook(game->mlx, &key_calls, game);
	mlx_loop(game->mlx);
	mlx_delete_texture(game->no_txt);
	mlx_delete_texture(game->so_txt);
	mlx_delete_texture(game->ea_txt);
	mlx_delete_texture(game->we_txt);
	mlx_terminate(game->mlx);
}
