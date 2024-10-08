/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:33:23 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/08 13:49:33 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_error(char *msg)
{
	int	i;

	i = 0;
	//free function here

	while (msg[i])
		write(1, &msg[i++], 1);
	exit (1);
}