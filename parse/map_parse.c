/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:25:36 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/10 16:44:29 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_coordinates(t_data *data)
{
	if (data->dup_flag == 1)
	{
		free_structs(data);
		ft_error("Error: duplicate paths");
	}
	if (!is_empty_coord(data))
	{
		free_structs(data);
		ft_error("Error: empty coordinates");
	}
	if (!try_to_open(data))
	{
		free_structs(data);
		ft_error("Error: can't open PATH");
	}
}

void	check_map(char *str, t_data *data)
{
	int	fd;
	int	len;
	
	len = ft_strlen(str) - 4;
	fd = open(str, O_RDONLY);
	if (fd == -1 || !ft_strnstr(str + len, ".cub", 4))
			ft_error("Error: Can't open the map\n");
	find_coordinates(fd, data);
	find_map(fd, data);
	close (fd);
	parse_coordinates(data); // TODO
	//parse_map(data); // TODO
}