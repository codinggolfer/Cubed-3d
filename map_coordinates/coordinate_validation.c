/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_validation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:46:53 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/24 16:58:20 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty_coord(t_data *data)
{
	if (!data->img->no)
		return (0);
	if (!data->img->so)
		return (0);
	if (!data->img->ea)
		return (0);
	if (!data->img->we)
		return (0);
	return (1);
}

static int open_check(char *path)
{
	int fd;
	int	len;

	len = ft_strlen(path) - 4;
	fd = open(path, O_RDONLY);
	if (fd == -1 || !ft_strnstr(path + len, ".png", 4))
		return (0);
	close(fd);
	return (1);
}

int	try_to_open(t_data *data)
{
	if (!open_check(data->img->no))
		return (0);
	if (!open_check(data->img->so))
		return (0);
	if (!open_check(data->img->ea))
		return (0);
	if (!open_check(data->img->we))
		return (0);
	return (1);
}

int	check_values(char **num_arr)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	if (count_arg_array(num_arr) != 3)
		return (1);
	while (num_arr[i])
	{
		while (num_arr[i][j])
		{
			if (!ft_isdigit(num_arr[i][j]))
				return (1);
			if (j > 4)
				return (1);
			j++;
		}
		j = 0;
		if (ft_atol(num_arr[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}
