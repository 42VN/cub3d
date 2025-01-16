/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:15:37 by hitran            #+#    #+#             */
/*   Updated: 2025/01/16 09:58:53 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mylib.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "MLX42.h"

typedef enum e_obj_type
{
	SPACE,
	WALL,
	NORTH,
	SOUTH,
	EAST,
	WEST,
	EMPTY
}	t_obj_type;

typedef enum e_elem_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_elem_type;

typedef struct s_point
{
	int32_t	row;
	int32_t	col;
}	t_point;

typedef struct s_map
{
	char	**arr;
	int32_t	rows;
	int32_t	cols;
	int32_t	e_paths;
	t_point	start;
}	t_map;

typedef struct s_element
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
}	t_element;

typedef struct s_cub3d
{
	t_element	*element;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	**image;
	t_point		current;
	t_point		next;
}	t_cub3d;

//		GAME		//

//		MAP			//
void	read_map(t_element *element, t_map *map, int32_t fd);

//		UTILS		//

#endif