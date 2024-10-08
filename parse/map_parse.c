/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:25:36 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/08 13:51:51 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_map(char *str)
{
	int	fd;
	int	len;
	
	len = ft_strlen(str) - 4;
	fd = open(str, O_RDONLY);
	if (fd == -1 || !ft_strnstr(str + len, ".cub", 4))
			ft_error("Error: Can't open the map\n");
	
	close (fd);
	exit (0);
}