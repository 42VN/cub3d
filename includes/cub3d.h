/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:15:37 by hitran            #+#    #+#             */
/*   Updated: 2025/01/17 14:10:44 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mylib.h"
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "MLX42.h"
# include "map_cub3d.h"

typedef struct s_cub3d
{
	t_element	*element;
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	**image;
	t_point		current;
	t_point		next;
}	t_cub3d;

#endif