/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:33:23 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/09 15:05:58 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_error(char *msg)
{
	int	i;

	i = 0;
	//free function here

	while (msg[i])
		write(1, &msg[i++], 1);
	exit (1);
}

void	free_2darray(char **array)
{
	int	i;
	int	len;

	i = 0;
	if (!array)
		return ;
	len = count_arg_array(array);
	while (i < len)
	{
		free (array[i]);
		i++;
	}
	free (array);
}

int	count_arg_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] != NULL)
		i++;
	return (i);
}

void free_structs(t_data *data)
{
	free (data->img->ceiling);
	free (data->img->floor);
	free (data->img->ea);
	free (data->img->so);
	free (data->img->we);
	free (data->img->no);
	free (data->img);
	free (data);
}