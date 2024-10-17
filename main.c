/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/17 13:04:05 by eagbomei         ###   ########.fr       */
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
		init_game(game, data);
		run_game(game); // TODO
		//free_stuff(); //TODO
	}
	else
		ft_printf ("%s\n", "invalid amount of arguments");
	// mlx_loop_hook(game.mlx, &game_loop, &game);
	// mlx_loop(game.mlx);
	free_structs(data);	//add game struct frees
	exit (0);
}
