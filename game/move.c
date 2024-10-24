/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:47:08 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/24 17:25:34 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_game *game, t_player *p)
{
	double	new_x;
	double	new_y;

	new_x = p->pos_x + p->dir_x * MOVE_SPEED;
	new_y = p->pos_y + p->dir_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(new_x)] == '0')
		p->pos_x = new_x;
	if (game->map[(int)(new_y)][(int)(p->pos_x)] == '0')
		p->pos_y = new_y;
}

void	move_down(t_game *game, t_player *p)
{
	double	new_x;
	double	new_y;

	new_x = p->pos_x - p->dir_x * MOVE_SPEED;
	new_y = p->pos_y - p->dir_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(new_x)] == '0')
		p->pos_x = new_x;
	if (game->map[(int)(new_y)][(int)(p->pos_x)] == '0')
		p->pos_y = new_y;
}

void	strife_left(t_game *game, t_player *p)
{
	double	strafe_x;
	double	strafe_y;
	double	new_x;
	double	new_y;

	strafe_x = p->dir_y;
	strafe_y = -p->dir_x;
	new_x = p->pos_x + strafe_x * MOVE_SPEED;
	new_y = p->pos_y + strafe_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(new_x)] == '0')
		p->pos_x = new_x;
	if (game->map[(int)(new_y)][(int)(p->pos_x)] == '0')
		p->pos_y = new_y;
}

void	strife_right(t_game *game, t_player *p)
{
	double	strafe_x;
	double	strafe_y;
	double	new_x;
	double	new_y;

	strafe_x = -p->dir_y;
	strafe_y = p->dir_x;
	new_x = p->pos_x + strafe_x * MOVE_SPEED;
	new_y = p->pos_y + strafe_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(new_x)] == '0')
		p->pos_x = new_x;
	if (game->map[(int)(new_y)][(int)(p->pos_x)] == '0')
		p->pos_y = new_y;
}
