/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:15:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/07 17:37:23 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "MLX42.h"
# include "utility.h"

typedef struct s_cub	t_cub;

typedef enum e_elem_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_elem_type;

typedef struct s_map
{
	int		no_fd;
	int		so_fd;
	int		we_fd;
	int		ea_fd;
	int		f_color;
	int		c_color;

	int		width;
	int		height;

	char	**grid;
	int		size;
	int		max_rows;
	int		max_cols;
}	t_map;

//--------------------------------------------
// READ
//--------------------------------------------
int		read_map(t_cub *cub, int fd);
int 	read_element(t_map *map,char *line);
int		read_grid(t_map *map, char *line);
int		validate_grid(t_cub *cub, int fd);

//--------------------------------------------
// UTILS
//--------------------------------------------
void	clean_map(t_map *map);
int		map_error(t_map *map, char *line, int fd);
void	print_map(t_map *map);
bool	is_done(t_map *map);
int		copy_grid(char **visited, t_map *map);
int		realloc_map(t_map *map);

#endif