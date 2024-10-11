/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_fill_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:27:00 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/11 17:01:32 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_nl(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			data->nl_flag = 1;
		i++;
	}
}

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
	check_nl(line, data);
	data->img->map = ft_split(line, '\n');
	free (line);
}
