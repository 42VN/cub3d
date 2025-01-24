/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:15:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/24 10:42:26 by hitran           ###   ########.fr       */
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
	int	row;
	int	col;
}	t_point;

typedef struct s_element
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_color	floor;
	t_color	ceiling;
	int		done;
}	t_element;


typedef struct s_map
{
	char		**arr;
	int			size;
	int			max_rows;
	int			max_cols;
	t_point		start;
	t_obj_type	direction;
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

//--------------------------------------------
// ERROR
//--------------------------------------------
int		read_map_error(t_element *element, t_map *map, char *line, int fd);
int		read_elem_error(t_element *element, char *line, int fd);

//--------------------------------------------
// DEBUG
//--------------------------------------------
void	print_elements(t_element *elem);
void	print_map(char **map);

#endif