/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/16 17:02:34 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void game_loop(void* param)
// {
//     t_game* game = (t_game*)param;
    
//     ray_casting(game);
//     //handle_input(game);
//     //-->actions to key presses, move player, roatate player
// }

int main(int ac, char **av)
{
	t_data	*data;
	t_game	*game;

	data = NULL;
	game = NULL;
	data = malloc(sizeof(t_data));
	data->img = malloc(sizeof(t_img));
	init_data(data);
	game = malloc(sizeof(t_game));
	if (ac != 3)
	{
		check_map(av[1], data);
		//init_game(); //TOOD
		//run_game(); // TODO
		//free_stuff(); //TODO
	}
	else
		ft_printf ("%s\n", "invalid amount of arguments");
	init_game(game, data);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
	free_structs(data);	//add game struct frees
	exit (0);
}
