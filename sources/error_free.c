/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:33:23 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/24 17:40:30 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *msg)
{
	int	i;

	i = 0;
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

void	free_structs(t_data *data)
{
	if (data->img->ceiling)
		free (data->img->ceiling);
	if (data->img->floor)
		free (data->img->floor);
	if (data->img->ea)
		free (data->img->ea);
	if (data->img->so)
		free (data->img->so);
	if (data->img->we)
		free (data->img->we);
	if (data->img->no)
		free (data->img->no);
	if (data->img->map)
		free_2darray(data->img->map);
	if (data->img->top)
		free (data->img->top);
	free (data->img);
	free (data);
}
