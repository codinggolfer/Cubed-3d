/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_fill_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:27:00 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/22 13:25:51 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_nl(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 9000)
	{
		free(str);
		free_structs(data);
		ft_error("Error\nmap size cap hit");
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			data->nl_flag = 1;
		if (str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W')
			data->dup_char++;
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
