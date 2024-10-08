/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:07:01 by eagbomei          #+#    #+#             */
/*   Updated: 2024/10/08 14:45:14 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>

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
}	t_img;


typedef struct s_data
{
	t_img *img;
}	t_data;

void	check_map(char *str);
void	ft_error(char *msg);

#endif