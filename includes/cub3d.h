/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:20:47 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 18:25:29 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 1280
# define HEIGHT 960
# define PI 3.14159265359
# define FOV = PI / 2

#include <stdio.h>
#include "libft.h"
#include "asset_manager.h"
#include "map.h"
#include "utility.h"
#include "player.h"

typedef struct s_cub
{
	t_map			map;
	t_player		player;
	mlx_t			*mlx;
	int32_t			mouse_x;
	int32_t			mouse_y;
	t_asset_manager	am;
}	t_cub;

void	cub3d_init(t_cub *cub);
void	cub3d_display(t_cub *c);
void	cub3d_free(t_cub *c);
void	cub3d_error_exit(t_cub *c, char *str);

//-------------------------------------------
// EVENTS
//-------------------------------------------
void	event_loop_handler(void	*data);
void	event_close_handler(void *data);

void	ft_image_to_window(
			t_cub *cub,
			mlx_image_t *img,
			int32_t x, int32_t y);

#endif