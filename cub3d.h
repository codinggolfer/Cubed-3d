/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:07:01 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/11 14:04:57 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h> //remove if needed

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
}	t_data;

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

//free functions here
void	ft_error(char *msg);
int		count_arg_array(char **array);
void	free_2darray(char **array);
void	free_structs(t_data *data);



#endif