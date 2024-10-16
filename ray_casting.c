/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:14:45 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/16 14:53:30 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_vertical_line(mlx_image_t *img, int x, int start, int end, uint32_t color)
{
    for (int y = start; y < end; y++)
        mlx_put_pixel(img, x, y, color);
}

void calculate_step_and_side_dist(t_ray *ray, t_player *player)
{
    if (ray->rayDirX < 0)
    {
        ray->stepX = -1;
        ray->sideDistX = (player->posX - ray->mapX) * ray->deltaDistX;
    }
    else
    {
        ray->stepX = 1;
        ray->sideDistX = (ray->mapX + 1.0 - player->posX) * ray->deltaDistX;
    }
    if (ray->rayDirY < 0)
    {
        ray->stepY = -1;
        ray->sideDistY = (player->posY - ray->mapY) * ray->deltaDistY;
    }
    else
    {
        ray->stepY = 1;
        ray->sideDistY = (ray->mapY + 1.0 - player->posY) * ray->deltaDistY;
    }
}

void perform_dda(t_ray *ray, char **map)
{
    while (ray->hit == 0)
    {
        if (ray->sideDistX < ray->sideDistY)
        {
            ray->sideDistX += ray->deltaDistX;
            ray->mapX += ray->stepX;
            ray->side = 0;
        }
        else
        {
            ray->sideDistY += ray->deltaDistY;
            ray->mapY += ray->stepY;
            ray->side = 1;
        }
        if (map[ray->mapY][ray->mapX] == '1')
            ray->hit = 1;
    }
}

void calculate_wall_height(t_ray *ray, t_player *player, int *drawStart, int *drawEnd)
{
    if (ray->side == 0)
        ray->perpWallDist = (ray->mapX - player->posX + (1 - ray->stepX) / 2) / ray->rayDirX;
    else
        ray->perpWallDist = (ray->mapY - player->posY + (1 - ray->stepY) / 2) / ray->rayDirY;

    int lineHeight = (int)(SCREEN_HEIGHT / ray->perpWallDist);
    *drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
    *drawStart = (*drawStart < 0) ? 0 : *drawStart;
    *drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
    *drawEnd = (*drawEnd >= SCREEN_HEIGHT) ? SCREEN_HEIGHT - 1 : *drawEnd;
}

void ray_casting(t_game *game)
{
    t_ray ray;
    int drawStart, drawEnd;

    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        init_ray(&ray, &game->player, x);
        calculate_step_and_side_dist(&ray, &game->player);
        perform_dda(&ray, game->map);
        calculate_wall_height(&ray, &game->player, &drawStart, &drawEnd);

        uint32_t color = (ray.side == 1) ? 0xFF0000FF : 0x00FF00FF;
        draw_vertical_line(game->img, x, drawStart, drawEnd, color);
    }
}
