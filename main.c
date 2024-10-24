/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/24 17:15:50 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_game	*game;

	data = NULL;
	game = NULL;
	data = malloc(sizeof(t_data));
	data->img = malloc(sizeof(t_img));
	init_data(data);
	if (ac == 2)
	{
		check_map(av[1], data);
		game = malloc(sizeof(t_game));
		init_game(game, data);
		run_game(game);
	}
	else
		ft_printf ("%s\n", "invalid amount of arguments");
	free(game);
	free_structs(data);
	return (0);
}
