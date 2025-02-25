/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:15:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/25 14:05:48 by hitran           ###   ########.fr       */
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
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
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
bool	is_enclosed(t_map *map, t_dpoint start);
int		validate_png(char *path);

//--------------------------------------------
// UTILS
//--------------------------------------------
void	clean_map(t_map *map);
int		map_error(t_map *map, char *line, int fd);
void	print_map(t_map *map);
bool	is_done(t_map *map);

#endif