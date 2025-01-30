/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:20:47 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/30 15:26:26 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 1280
# define HEIGHT 960
# define PI 3.14159265359
# define FOV = PI / 2

#include "libft.h"
#include "asset_manager.h"
#include "map.h"
#include "utility.h"
#include "minimap.h"

typedef struct s_cub3d
{
	t_map			map;
	mlx_t			*mlx;
	int32_t			mouse_x;
	int32_t			mouse_y;
	t_point			current;
	t_point			next;
	t_asset_manager	am;
}	t_cub3d;

void	cub3d_init(t_cub3d *cub);
void	cub3d_render(t_cub3d *c);
void	cub3d_free(t_cub3d *c);
void	cub3d_error_exit(t_cub3d *c, char *str);

//-------------------------------------------
// EVENTS
//-------------------------------------------
void	event_loop_handler(void	*data);
void	event_close_handler(void *data);

#endif