/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:16:08 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 13:59:07 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

# include "utility.h"
# include "MLX42.h"

typedef enum e_sprite_dir
{
	DIR_HORIZONTAL,
	DIR_VERTICAL
}	e_sprite_dir;

typedef struct s_sprite_options
{
	uint32_t		rows;
	uint32_t		cols;
	e_sprite_dir	dir;
}	t_sprite_options;

typedef struct s_sprite
{
	mlx_image_t	**frames;
	uint32_t	frame_w;
	uint32_t	frame_h;
	uint32_t	rows;
	uint32_t	cols;
}	t_sprite;

typedef struct s_asset_manager
{
	mlx_image_t	*walls[4];
	mlx_image_t	*door;
	t_sprite	*sprite_weapon;
}	t_asset_manager;


void		am_free(mlx_t *mlx, t_asset_manager *am);
mlx_image_t	*am_load_img(mlx_t *mlx, char *path);
t_sprite	*am_load_sprite(mlx_t *mlx, t_sprite_options options, char *path);

#endif