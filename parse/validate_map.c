/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:03:16 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/11 16:47:31 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	top_bottom_border(char *border)
{
	int	i;

	i = 1;
	if (border[0] != '1' && border[ft_strlen(border) - 1] != '1')
		return (1);
	while (border[i] != '\0')
	{
		if (border[i] != '1' && border[i] != ' ' && border[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}
int	check_surround(char *top, char *bottom, int i)
{
	if (!top[i] || !bottom[i])
		return (0);
	if (top[i] == '\n' || bottom[i] == '\n')
		return (0);
	if (top[i] != '0' && top[i] != '1'
		&& !ft_strchr("NSEW", top[i]))
		return (0);
	if (bottom[i] != '0' && bottom[i] != '1'
		&& !ft_strchr("NSEW", bottom[i]))
		return (0);
	return (1);
}

int	inside_map(char *line, char *top, char *bottom)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			if (!check_surround(top, bottom, i))
				return (2);
		}
		i++;
	}
	return (0);
	
}

int	validate_map(char **map)
{
	int	i;
	int	flag;
	int	len;

	len = count_arg_array(map) - 1;
	i = 1;
	flag = 0;
	flag = top_bottom_border(map[0]);
	if (flag)
		return (1);
	while (i <= len - 1)
	{
		flag = inside_map(map[i], map[i - 1], map[i + 1]);
		if (flag)
			return (2);
		i++;
	}
	flag = top_bottom_border(map[len]);
	if (flag)
		return (1);
	return (0);
	
}
