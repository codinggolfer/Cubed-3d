/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:43:25 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/24 17:32:59 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_calls(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		ft_printf("Game closed ESQ was pressed\n");
		mlx_close_window(game->mlx);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rot_right(&game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rot_left(&game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_up(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_down(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		strife_left(game, &game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		strife_right(game, &game->player);
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ray_casting(game);
}

int	ft_longest(char **map)
{
	static int	lenght;
	int			i;

	if (lenght && lenght > 0)
		return (lenght);
	lenght = 0;
	i = 0;
	while (map[i])
	{
		if (lenght < (int)ft_strlen(map[i]))
			lenght = ft_strlen(map[i]);
		i++;
	}
	return (lenght);
}

void	run_game(t_game *game)
{
	game->width = ft_longest(game->map);
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_loop_hook(game->mlx, &key_calls, game);
	mlx_loop(game->mlx);
	mlx_delete_texture(game->no_txt);
	mlx_delete_texture(game->so_txt);
	mlx_delete_texture(game->ea_txt);
	mlx_delete_texture(game->we_txt);
	mlx_terminate(game->mlx);
}
