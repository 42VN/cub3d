/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:15:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 10:57:37 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "MLX42.h"
# include "utility.h"
// # include "cub3d.h"
#include "utility.h"
typedef struct s_cub	t_cub;

// typedef enum e_obj_type
// {
// 	SPACE,
// 	WALL,
// 	PLAYER,
// 	NORTH,
// 	SOUTH,
// 	EAST,
// 	WEST,
// 	EMPTY
// }	t_obj_type;

typedef enum e_elem_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_elem_type;

// typedef enum e_direction
// {
// 	O,
// 	N,
// 	S,
// 	W,
// 	E
// }	t_direction;

// typedef struct s_point
// {
// 	int			x;
// 	int			y;
// 	double		rad;
// }	t_point;

// typedef struct s_element
// {
// 	int		no_fd;
// 	int		so_fd;
// 	int		we_fd;
// 	int		ea_fd;
// 	int		f_color;
// 	int		c_color;
// 	int		done;
// }	t_map;


typedef struct s_map
{
	int		no_fd;
	int		so_fd;
	int		we_fd;
	int		ea_fd;
	int		f_color;
	int		c_color;

	char	**grid;
	int		size;
	int		max_rows;
	int		max_cols;
}	t_map;

//--------------------------------------------
// CLEAN
//--------------------------------------------
// void	clean_elems(t_map *map);
void	clean_map(t_map *map);

//--------------------------------------------
// READ
//--------------------------------------------
int		read_map(t_cub *cub, int fd);
int 	read_element(t_map *map,char *line);
int		read_grid(t_map *map, char *line);
int		validate_grid(t_cub *cub, int fd);
int		copy_grid(char **visited, t_map *map, char rest);
bool	is_done(t_map *map);
//--------------------------------------------
// ERROR
//--------------------------------------------
int		map_error(t_map *map, char *line, int fd);

//--------------------------------------------
// DEBUG
//--------------------------------------------
// void	print_maps(t_map *elem);
void	print_map(t_map *map);

#endif