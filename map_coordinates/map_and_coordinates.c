/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:44:02 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/09 14:40:54 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fill_coordinates(char **coordArr, t_data *data)
{
	int	i;

	i = 0;
	while (coordArr[i])
	{
		//printf("here\n");	
		if (ft_strncmp("NO ", coordArr[i], 3))
			fill_coord_struct_no(coordArr[i], data);
		else if (ft_strncmp("SO ", coordArr[i], 3))
			fill_coord_struct_so(coordArr[i], data);
		else if (ft_strncmp("WE ", coordArr[i], 3))
			fill_coord_struct_we(coordArr[i], data);
		else if (ft_strncmp("EA ", coordArr[i], 3))
			fill_coord_struct_ea(coordArr[i], data);
		else if (ft_strncmp("C ", coordArr[i], 2))
			fill_ceiling_struct(coordArr[i], data);
		else if (ft_strncmp("F ", coordArr[i], 2))
			fill_floor_struct(coordArr[i], data);
		i++;
	}
	free_2darray(coordArr);
}

void	find_coordinates(int fd, t_data *data)
{
	char 	*line;
	char 	*temp;

	line = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp && ft_isdigit(temp[0]))
		{
			free(temp);
			break ;
		}
		if (temp == NULL)
			break ;
		if (!line)
			line = ft_strdup(temp);
		else if (line)
			line = append_line(line, temp);
		if (!line)
			ft_error("Error: malloc failure in strdup or strjoin");
		free(temp);
	}
	fill_coordinates(ft_split(line, '\n'), data);
}
