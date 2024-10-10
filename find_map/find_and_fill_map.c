/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_fill_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:27:00 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/10 13:52:03 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void find_map(int fd, t_data *data)
{
	char 	*line;
	char 	*temp;

	if (data->img->top)
		line = ft_strdup(data->img->top);
	else
		return ;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		else if (line)
			line = append_line(line, temp);
		if (!line)
			ft_error("Error: malloc failure in strdup or strjoin");
		free(temp);
	}
	data->img->map = ft_split(line, '\n');
	free (line);
}