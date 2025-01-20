/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cub3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:15:37 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 15:11:56 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CUB3D_H
# define MAP_CUB3D_H

# define BUFFER_SIZE 1000

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

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	done;
}	t_color;

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

//		MAP			//
int		read_file(t_element *element, t_map *map, int fd);
int 	read_element(t_element *element, char *line);
int		read_map(t_map *map, char *line);

//		UTILS		//
char	*read_line(int fd, int *eof, int size);
void	set_color(t_color *color, char **array);
int		validate_map_path(char *path);
int		validate_elem_path(char *path);

//		ERROR		//
int 	error_int(char *message1, char *message2);
char 	*error_str(char *str, char *message);
int		read_elem_error(t_element *element, char *line, int fd);
int		read_map_error(t_element *element, t_map *map, char *line, int fd);

//TEST
void	print_elements(t_element *elem);
void	print_map(t_map *map);

#endif