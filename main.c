/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/11 17:02:18 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(t_data *data)
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
	data->nl_flag = 0;
}

int main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	data->img = malloc(sizeof(t_img));
	init_struct(data);
	if (ac != 3)
	{
		check_map(av[1], data);
		
		// printf("%s\n", data->img->no);
		// printf("%s\n", data->img->ea);
		// printf("%s\n", data->img->we);
		// printf("%s\n", data->img->so);
		// printf("ceiling: %s\n", data->img->ceiling);
		// printf("floor: %s\n", data->img->floor);
		// for (int i = 0; data->img->map[i] != NULL; i++)
		// 	printf("%s\n", data->img->map[i]);
		//init_game(); //TOOD
		//run_game(); // TODO
		//free_stuff(); //TODO
	}
	else
		ft_printf ("%s\n", "invalid amount of arguments");
	free_structs(data);
	exit (0);
}