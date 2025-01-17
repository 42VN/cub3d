/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:15:37 by hitran            #+#    #+#             */
/*   Updated: 2025/01/17 13:20:43 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mylib.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "MLX42.h"

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
	char	**arr;
	int		max_rows;
	int		max_cols;
	t_point	start;
}	t_map;

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
int		read_file(t_element *element, t_map *map, int fd);
int 	read_element(t_element *element, char *line);

//		UTILS		//
char	*read_line(int fd, int size);
void	set_color(t_color color, char **array);

//		ERROR		//
int 	error_int(char *message);
char 	*error_str(char **str, char *message);
char	*bad_alloc(char **str);
int		read_elem_error(t_element *element, char *line, int fd);

#endif