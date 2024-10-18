/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:47:08 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/18 18:04:22 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_game *game, t_player *p)
{
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * MOVE_SPEED)] == '0')
        p->pos_x += p->dir_x * MOVE_SPEED;
   	if (game->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * MOVE_SPEED)] == '0')
        p->pos_y += p->dir_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * MOVE_SPEED)] == '1')
		p->pos_y -= p->dir_y * MOVE_SPEED;
}
void	move_down(t_game *game, t_player *p)
{
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * MOVE_SPEED)] == '0')
        p->pos_x -= p->dir_x * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * MOVE_SPEED)] == '0')
        p->pos_y -= p->dir_y * MOVE_SPEED;
	if (game->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x * MOVE_SPEED)] == '1')
		p->pos_y += p->dir_y * MOVE_SPEED;
}
void	rot_right(t_player *p)
{
	double old_dir_x = p->dir_x;
    p->dir_x = p->dir_x * cos(ROTATE_SPEED) - p->dir_y * sin(ROTATE_SPEED);
    p->dir_y = old_dir_x * sin(ROTATE_SPEED) + p->dir_y * cos(ROTATE_SPEED);

    double old_plane_x = p->plane_x;
    p->plane_x = p->plane_x * cos(ROTATE_SPEED) - p->plane_y * sin(ROTATE_SPEED);
    p->plane_y = old_plane_x * sin(ROTATE_SPEED) + p->plane_y * cos(ROTATE_SPEED);
}

void	rot_left(t_player *p)
{
	double old_dir_x = p->dir_x;
    p->dir_x = p->dir_x * cos(-ROTATE_SPEED) - p->dir_y * sin(-ROTATE_SPEED);
    p->dir_y = old_dir_x * sin(-ROTATE_SPEED) + p->dir_y * cos(-ROTATE_SPEED);

    double old_plane_x = p->plane_x;
    p->plane_x = p->plane_x * cos(-ROTATE_SPEED) - p->plane_y * sin(-ROTATE_SPEED);
    p->plane_y = old_plane_x * sin(-ROTATE_SPEED) + p->plane_y * cos(-ROTATE_SPEED);
}