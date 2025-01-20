/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:20:47 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 16:52:36 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# define WIDTH 1280
# define HEIGHT 960

#include "libft.h"
#include "asset_manager.h"
#include "map.h"
#include "utility.h"


typedef struct s_cub3d
{
	mlx_t			*mlx;
	t_element		*element;
	t_map			*map;
	t_asset_manager	am;
}	t_cub3d;

int		cub3d_init(t_cub3d *cub);
void	cub3d_free(t_cub3d *c);

#endif