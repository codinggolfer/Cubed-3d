/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:43:25 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/17 16:47:01 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
void game_loop(void* param)
{
    t_game* game = (t_game*)param;
    
    ray_casting(game);
    //handle_input(game);
    //-->actions to key presses, move player, roatate player
}

void	run_game(t_game *game)
{
	mlx_loop_hook(game->mlx, &game_loop, &game);
	mlx_loop(game->mlx);
}