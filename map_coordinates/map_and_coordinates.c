/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:44:02 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/24 13:44:10 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fill_coordinates(char **coordArr, t_data *data)
{
	int	i;

	i = 0;
	if (count_arg_array(coordArr) > 6)
		data->dup_flag = 1;
	while (coordArr[i])
	{
		if (!ft_strncmp("NO ", coordArr[i], 3))
			fill_coord_struct_no(coordArr[i], data);
		else if (!ft_strncmp("SO ", coordArr[i], 3))
			fill_coord_struct_so(coordArr[i], data);
		else if (!ft_strncmp("WE ", coordArr[i], 3))
			fill_coord_struct_we(coordArr[i], data);
		else if (!ft_strncmp("EA ", coordArr[i], 3))
			fill_coord_struct_ea(coordArr[i], data);
		else if (!ft_strncmp("C ", coordArr[i], 2))
			fill_ceiling_struct(coordArr[i], data);
		else if (!ft_strncmp("F ", coordArr[i], 2))
			fill_floor_struct(coordArr[i], data);
		i++;
	}
	free_2darray(coordArr);
}

void	find_coordinates(int fd, t_data *data)
{
	char 	*line;
	char 	*t;

	line = NULL;
	while (1)
	{
		t = get_next_line(fd);
		if (t && (ft_isdigit(t[0]) || t[0] == '\t' || t[0] == ' '))
		{
			data->img->top = ft_strdup(t);
			free(t);
			break ;
		}
		if (t == NULL)
			break ;
		if (!line)
			line = ft_strdup(t);
		else if (line)
			line = append_line(line, t);
		if (!line)
			ft_error("Error\n malloc failure in strdup or strjoin");
		free(t);
	}
	fill_coordinates(ft_split(line, '\n'), data);
	free (line);
}
