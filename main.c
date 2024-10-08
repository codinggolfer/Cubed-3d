/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:12:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/08 16:30:12 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_data	data;

	
	if (ac != 3)
	{
		check_map(av[1]);

		
		//init_game(); //TOOD
		//run_game(); // TODO
		//free_stuff(); //TODO
	}
	

	ft_printf ("%s\n", "invalid amount of arguments");
	return (0);
}