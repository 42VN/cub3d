/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:20:47 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/27 13:56:25 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 1280
# define HEIGHT 960
# define PI 3.14159265359
# define FOV 1.04719755120 //= PI / 3
# define CELL_PX 32

#include <stdio.h>
#include <float.h>
#include <math.h>

#include "libft.h"
#include "asset_manager.h"
#include "map.h"
#include "utility.h"
#include "player.h"
#include "ray.h"

typedef struct s_cub
{
	t_map			map;
	t_player		player;
	t_ray			**rays;
	mlx_t			*mlx;
	int32_t			mouse_x;
	int32_t			mouse_y;
	t_asset_manager	am;
	mlx_image_t		**mini;
}	t_cub;

void	cub3d_init(t_cub *cub);
void	cub3d_display(t_cub *c);
void	cub3d_free(t_cub *c);
void	cub3d_exit(t_cub *c, int status);
void	cub3d_error_exit(t_cub *c, char *str);
void	init_rays(t_cub *cub);

//-------------------------------------------
// EVENTS
//-------------------------------------------
void 	key_inputs(t_cub *c);
void 	mouse_inputs(t_cub *c);
void 	inputs(t_cub *c);

void	collision(t_cub *c);

void	draw_map(t_cub *c);
void	draw_minimap(t_cub *c);
void	draw_player(t_cub *c);
void	draw_scene(t_cub *c);

void	animate(t_cub *c);
void	animate_player(t_cub *c, double elapsed_time);

void	event_loop_handler(void	*data);
void	event_close_handler(void *data);

void	ft_image_to_window(
			t_cub *cub,
			mlx_image_t *img,
			int32_t x, int32_t y);

#endif