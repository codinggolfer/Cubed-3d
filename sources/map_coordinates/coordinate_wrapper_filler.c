/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_wrapper_filler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:16:29 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/24 17:40:05 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_coord_struct_no(char *coordStr, t_data *data)
{
	if (data->img->no)
	{
		data->dup_flag = 1;
		return ;
	}
	while (*coordStr != '\0' && *coordStr != '.')
	{
		if (*coordStr == '\0')
			return ;
		coordStr++;
	}
	if (*coordStr == '\0')
		data->img->no = ft_strdup("");
	else
		data->img->no = ft_strdup(coordStr);
	if (!data->img->no)
		return ;
}

void	fill_coord_struct_so(char *coordStr, t_data *data)
{
	if (data->img->so)
	{
		data->dup_flag = 1;
		return ;
	}
	while (*coordStr != '\0' && *coordStr != '.')
	{
		if (*coordStr == '\0')
			return ;
		coordStr++;
	}
	if (*coordStr == '\0')
		data->img->so = ft_strdup("");
	data->img->so = ft_strdup(coordStr);
	if (!data->img->so)
		return ;
}

void	fill_coord_struct_we(char *coordStr, t_data *data)
{
	if (data->img->we)
	{
		data->dup_flag = 1;
		return ;
	}
	while (*coordStr != '\0' && *coordStr != '.')
	{
		if (*coordStr == '\0')
			return ;
		coordStr++;
	}
	if (*coordStr == '\0')
		data->img->we = ft_strdup("");
	data->img->we = ft_strdup(coordStr);
	if (!data->img->we)
		return ;
}

void	fill_coord_struct_ea(char *coordStr, t_data *data)
{
	if (data->img->ea)
	{
		data->dup_flag = 1;
		return ;
	}
	while (*coordStr != '\0' && *coordStr != '.')
	{
		if (*coordStr == '\0')
			return ;
		coordStr++;
	}
	if (*coordStr == '\0')
		data->img->ea = ft_strdup("");
	data->img->ea = ft_strdup(coordStr);
	if (!data->img->ea)
		return ;
}
