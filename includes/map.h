/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:15:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/29 15:38:12 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "MLX42.h"
# include "utility.h"

#include "utility.h"

typedef enum e_obj_type
{
	SPACE,
	WALL,
	PLAYER,
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

typedef enum e_direction
{
	O,
	N,
	S,
	W,
	E
}	t_direction;

typedef struct s_point
{
	int			row;
	int			col;
	double		radian;
}	t_point;

typedef struct s_element
{
	int		no_fd;
	int		so_fd;
	int		we_fd;
	int		ea_fd;
	int		f_color;
	int		c_color;
	int		done;
}	t_element;


typedef struct s_map
{
	char		**arr;
	int			size;
	int			max_rows;
	int			max_cols;
	t_point		start;
}	t_map;

//--------------------------------------------
// CLEAN
//--------------------------------------------
void	clean_elems(t_element *element);
void	clean_map(t_map *map);

//--------------------------------------------
// READ
//--------------------------------------------
int		read_file(t_element *element, t_map *map, int fd);
int 	read_element(t_element *element, char *line);
int		read_map(t_map *map, char *line);
int		validate_map(t_element *element, t_map *map, int fd);
int		copy_map(char **visited, t_map *map, char rest);

//--------------------------------------------
// ERROR
//--------------------------------------------
int		map_error(t_element *element, t_map *map, char *line, int fd);

//--------------------------------------------
// DEBUG
//--------------------------------------------
void	print_elements(t_element *elem);
void	print_map(char **map);

#endif