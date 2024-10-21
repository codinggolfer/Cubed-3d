/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strife.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:42:51 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/21 11:40:43 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	strife_right(t_game *game, t_player *p)
{
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)] == '0')
		p->pos_x -= p->plane_x * MOVE_SPEED;
    if (game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)] == '0')
		p->pos_y -= p->plane_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)] == '1')
		p->pos_x += p->plane_x * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)] == '1')
		p->pos_y += p->plane_y * MOVE_SPEED;
}

void	strife_left(t_game *game, t_player *p)
{
	printf("x value: %c\n", game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)]);
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)] == '0')
        p->pos_x += p->plane_x * MOVE_SPEED;
   	if (game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)] == '0')
      	p->pos_y += p->plane_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)] == '1')
		p->pos_y -= p->plane_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x - p->plane_x * MOVE_SPEED)] == '1')
		p->pos_x -= p->plane_x * MOVE_SPEED;
}