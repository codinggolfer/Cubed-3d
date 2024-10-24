/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:25:36 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/24 13:37:28 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_coordinates(t_data *data)
{
	if (data->dup_char != 1)
	{
		free_structs(data);
		ft_error("Error\ninvalid amount of characters");
	}
	if (data->dup_flag == 1)
	{
		free_structs(data);
		ft_error("Error\nduplicate paths or other nonsense in the mapfile");
	}
	if (!is_empty_coord(data))
	{
		free_structs(data);
		ft_error("Error\nempty coordinates");
	}
	if (!try_to_open(data))
	{
		free_structs(data);
		ft_error("Error\ncan't open PATH");
	}
}

void	parse_ceiling(t_data *data)
{
	int		flag;
	char	**temp;

	flag = 0;
	
	if (!data->img->ceiling)
	{
		free_structs(data);
		ft_error("Error\nempty ceiling");
	}
	temp = ft_split(data->img->ceiling, ',');
	if (!temp)
	{
		free_structs(data);
		ft_error("Error\nincorrect ceiling");
	}
	else
		flag = check_values(temp);
	free_2darray(temp);
	if (flag == 1)
	{
		free_structs(data);
		ft_error("Error\nincorrect ceiling values");
	}
}

void	parse_floor(t_data *data)
{
	int		flag;
	char	**temp;

	flag = 0;
	
	if (!data->img->floor)
	{
		free_structs(data);
		ft_error("Error\nempty floor");
	}
	temp = ft_split(data->img->floor, ',');
	if (!temp)
	{
		free_structs(data);
		ft_error("Error\nincorrect floor");
	}
	else
		flag = check_values(temp);
	free_2darray(temp);
	if (flag == 1)
	{
		free_structs(data);
		ft_error("Error\nincorrect floor values");
	}
}

void	parse_map(t_data *data)
{
	int	flag;

	flag = 0;
	if (!data->img->map)
	{
		free_structs(data);
		ft_error("Error\nempty map");
	}
	if (data->nl_flag == 1)
	{
		free_structs(data);
		ft_error("Error\ninvalid map: unneed newlines");
	}
	flag = validate_map(data->img->map);
	if (flag)
	{
		free_structs(data);
		if (flag == 1)
			ft_error("Error\ninvalid map: invalid borders");
		if (flag == 2)
			ft_error("Error\ninvalid map: map borders open");
		if (flag == 3)
			ft_error("Error\ninvalid map: incorrect value");
			
	}
}

void	check_map(char *str, t_data *data)
{
	int	fd;
	int	len;
	
	len = ft_strlen(str) - 4;
	fd = open(str, O_RDONLY);
	if (fd == -1 || !ft_strnstr(str + len, ".cub", 4))
			ft_error("Error\nCan't open the map");
	find_coordinates(fd, data);
	find_map(fd, data);
	close (fd);
	parse_coordinates(data);
	parse_ceiling(data);
	parse_floor(data);
	data->dup_flag = 0;
	parse_map(data);
}
