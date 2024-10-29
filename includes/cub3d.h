/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:07:01 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/29 10:46:01 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h> //remove if needed

# define SCREEN_WIDTH 860
# define SCREEN_HEIGHT 640
# define MOVE_SPEED 0.0501
# define ROTATE_SPEED 0.03

typedef enum e_key
{
	RIGHT,
	LEFT,
	FORWARD,
	DOWN,
	S_LEFT,
	S_RIGHT
}	t_key;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray {
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		true_line_height;
}	t_ray;

typedef struct s_draw {
	double	texture_offset;
	int		start;
	int		end;
}	t_draw;

typedef struct s_game {
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		player;
	char			**map;
	char			**floor_rgb;
	char			**ceiling_rgb;
	mlx_texture_t	*no_txt;
	mlx_texture_t	*so_txt;
	mlx_texture_t	*ea_txt;
	mlx_texture_t	*we_txt;
	uint32_t		floor_colour;
	uint32_t		ceiling_colour;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			tex_scale;
	double			tex_pos;
	int				width;
}	t_game;

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
void	find_player_start(t_game *game, t_data *data);
int		create_trgb(char **floor);
int		position_direction_wrapper(t_game *game, int x, int y, char c);

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
void	ray_casting(t_game *game);
void	run_game(t_game *game);

//game rendering
void	draw_textured_wall_slice(t_game *game, t_ray *ray, t_draw draw, int x);
void	draw_floor_ceiling(mlx_image_t *img, int x, t_draw *draw, t_game *game);

//free functions here
void	ft_error(char *msg);
int		count_arg_array(char **array);
void	free_2darray(char **array);
void	free_structs(t_data *data);
void	check_empty(int *fd, t_data *data, char *str);

//move
void	move_up(t_game *game, t_player *p);
void	move_down(t_game *game, t_player *p);
void	rot_right(t_player *p);
void	rot_left(t_player *p);
void	strife_left(t_game *game, t_player *p);
void	strife_right(t_game *game, t_player *p);

#endif