/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_wrapper_filler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:16:29 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/09 16:06:37 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_coord_struct_no(char *coordStr, t_data *data)
{
	while (*coordStr != '.')
	{
		if (*coordStr == '\0')
			return ;
		coordStr++;
	}
	data->img->no = ft_strdup(coordStr);
	if (!data->img->no)
	{
		//free stuff here;
	}
}

void	fill_coord_struct_so(char *coordStr, t_data *data)
{
	while (*coordStr != '.')
	{
		if (*coordStr == '\0')
			return ;
		coordStr++;
	}
	data->img->so = ft_strdup(coordStr);
	if (!data->img->so)
	{
		//free stuff here;
	}
}

void	fill_coord_struct_we(char *coordStr, t_data *data)
{
	while (*coordStr != '.')
	{
		if (*coordStr == '\0')
			return ;
		coordStr++;
	}
	data->img->we = ft_strdup(coordStr);
	if (!data->img->we)
	{
		//free stuff here;
	}
}

void	fill_coord_struct_ea(char *coordStr, t_data *data)
{
	while (*coordStr != '.')
	{
		if (*coordStr == '\0')
			return ;
		coordStr++;
	}
	data->img->ea = ft_strdup(coordStr);
	if (!data->img->ea)
	{
		//free stuff here;
	}
}