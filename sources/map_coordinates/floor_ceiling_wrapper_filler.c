/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_wrapper_filler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:17:50 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/24 17:40:07 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_floor_struct(char *floor, t_data *data)
{
	int	comma;
	int	i;

	i = 0;
	comma = 0;
	if (data->dup_flag == 1)
		return ;
	while (floor[i++])
	{
		if (floor[i] == ',')
			comma++;
	}
	if (comma == 2)
		data->img->floor = ft_strtrim(floor + 1, " ");
	else
		data->img->floor = ft_strdup("");
}

void	fill_ceiling_struct(char *ceiling, t_data *data)
{
	int	comma;
	int	i;

	i = 0;
	comma = 0;
	if (data->dup_flag == 1)
		return ;
	while (ceiling[i++])
	{
		if (ceiling[i] == ',')
			comma++;
	}
	if (comma == 2)
		data->img->ceiling = ft_strtrim(ceiling + 1, " ");
	else
		data->img->ceiling = ft_strdup("");
}
