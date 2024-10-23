/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:42:51 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/23 10:44:06 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rot_right(t_player *p)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(ROTATE_SPEED) - p->dir_y * sin(ROTATE_SPEED);
	p->dir_y = old_dir_x * sin(ROTATE_SPEED) + p->dir_y * cos(ROTATE_SPEED);

	p->plane_x = p->plane_x * cos(ROTATE_SPEED) - p->plane_y * sin(ROTATE_SPEED);
	p->plane_y = old_plane_x * sin(ROTATE_SPEED) + p->plane_y * cos(ROTATE_SPEED);
}

void	rot_left(t_player *p)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(-ROTATE_SPEED) - p->dir_y * sin(-ROTATE_SPEED);
	p->dir_y = old_dir_x * sin(-ROTATE_SPEED) + p->dir_y * cos(-ROTATE_SPEED);

	p->plane_x = p->plane_x * cos(-ROTATE_SPEED) - p->plane_y * sin(-ROTATE_SPEED);
	p->plane_y = old_plane_x * sin(-ROTATE_SPEED) + p->plane_y * cos(-ROTATE_SPEED);
}