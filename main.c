/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/09 15:17:00 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->img = malloc(sizeof(t_img));
	if (ac != 3)
	{
		check_map(av[1], data);
		
		printf("%s\n", data->img->no);
		printf("%s\n", data->img->ea);
		printf("%s\n", data->img->we);
		printf("%s\n", data->img->so);
		printf("ceiling: %s\n", data->img->ceiling);
		printf("floor: %s\n", data->img->floor);
		//exit (0);
		//init_game(); //TOOD
		//run_game(); // TODO
		//free_stuff(); //TODO
	}
	else
		ft_printf ("%s\n", "invalid amount of arguments");
	free_structs(data);
	exit (0);
}