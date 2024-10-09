/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/09 14:41:53 by eagbomei         ###   ########.fr       */
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
		//printf("%s\n", data.img.);
		printf("%s\n", data->img->ea);
		printf("HERE\n");
		printf("%s\n", data->img->we);
		printf("%s\n", data->img->ceiling);
		printf("%s\n", data->img->floor);
		exit (0);
		//init_game(); //TOOD
		//run_game(); // TODO
		//free_stuff(); //TODO
	}
	

	ft_printf ("%s\n", "invalid amount of arguments");
	return (0);
}