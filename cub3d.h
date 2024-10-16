/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:07:01 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/16 16:54:32 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FOV 60
#define MOVE_SPEED 0.05
#define ROTATE_SPEED 0.03

# include "./libft/libft.h"
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h> //remove if needed

typedef struct s_player {
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
} t_player;

typedef struct s_ray {
	double 	cameraX;
	double 	rayDirX;
	double	rayDirY;
	int 	mapX;
	int		mapY;
	double 	sideDistX;
	double	sideDistY;
	double 	deltaDistX;
	double	deltaDistY;
	double 	perpWallDist;
	int 	stepX;
	int		stepY;
	int 	hit;
	int 	side;
} t_ray;

typedef struct s_game {
	mlx_t 		*mlx;
	mlx_image_t *img;
	t_player 	player;
	char 		**map;
} t_game;

// struct s_mlx
// {
	
// } mlx_t;

typedef struct s_img
{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*floor;
	char	*ceiling;
	char	**map;
	char	*top;
}	t_img;


typedef struct s_data
{
	t_img	*img;
	int		dup_flag;
	int		nl_flag;
	int		dup_char;
}	t_data;

//initializing structs
void	init_data(t_data *data);
void	init_game(t_game *game, t_data *data);
void	init_ray(t_ray *ray, t_player *player, int x);

//map parser here
void	check_map(char *str, t_data *data);
void	find_coordinates(int fd, t_data *data);

//coordinate, floor and ceiling filler wrapper functions
void	fill_coord_struct_no(char *coordStr, t_data *data);
void	fill_coord_struct_so(char *coordStr, t_data *data);
void	fill_coord_struct_we(char *coordStr, t_data *data);
void	fill_coord_struct_ea(char *coordStr, t_data *data);
void	fill_ceiling_struct(char *ceiling, t_data *data);
void	fill_floor_struct(char *floor, t_data *data);

//coordinate error wrapper validation functions
int		is_empty_coord(t_data *data);
int		try_to_open(t_data *data);
int		check_values(char **num_arr);

//map functions
void	find_map(int fd, t_data *data);
int		validate_map(char **map);

//game setup 
//void ray_casting(t_game *game);

//free functions here
void	ft_error(char *msg);
int		count_arg_array(char **array);
void	free_2darray(char **array);
void	free_structs(t_data *data);

//utils
void	init_data(t_data *data);



#endif