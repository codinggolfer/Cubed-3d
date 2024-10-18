/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:07:01 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/18 15:45:42 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "./libft/libft.h"
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h> //remove if needed

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define FOV 60
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.03

typedef enum e_key
{
	RIGHT,
	LEFT,
	FORWARD,
	DOWN,
	S_LEFT,
	S_RIGHT
	
} t_key;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
} t_player;

typedef struct s_ray {
	double 	camera_x;
	double 	ray_dir_x;
	double	ray_dir_y;
	int 	map_x;
	int		map_y;
	double 	side_dist_x;
	double	side_dist_y;
	double 	delta_dist_x;
	double	delta_dist_y;
	double 	perp_wall_dist;
	int 	step_x;
	int		step_y;
	int 	hit;
	int 	side;
} t_ray;

typedef struct s_game {
	mlx_t 		*mlx;
	mlx_image_t *img;
	t_player 	player;
	char 		**map;
	char		**floor_rgb;
	char		**ceiling_rgb;
	uint32_t	floor_colour;
	uint32_t	ceiling_colour;
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
void 	ray_casting(t_game *game);
void	run_game(t_game *game);
void	handle_input(t_game *game);

//free functions here
void	ft_error(char *msg);
int		count_arg_array(char **array);
void	free_2darray(char **array);
void	free_structs(t_data *data);

//move
void	move_up(t_game *game, t_player *p);
void	move_down(t_game *game, t_player *p);
void	rot_right(t_player *p);
void	rot_left(t_player *p);
void	strife_left(t_game *game, t_player *p);
void	strife_right(t_game *game, t_player *p);

//utils
//void	init_data(t_data *data); lets keep this in front page with main so there is space for wrapper function in init.c



#endif