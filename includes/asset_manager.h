/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:16:08 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/20 13:01:43 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H


# define M_OFFSET	    10
# define M_PLAYER_SIZE	10
# define M_PX		    32
# define M_SPACE		"./assets/textures/mini_space.png"
# define M_WALL			"./assets/textures/mini_wall.png"
# define M_PLAYER		"./assets/textures/mini_player3.png"
# define M_RAY			"./assets/textures/m_ray.png"
# define M_DOOR			"./assets/textures/m_door.png"

// #ifdef WIDTH
//  # define M_WIDTH (WIDTH / 5)
//  # define M_HEIGHT M_WIDTH
// #elif HEIGHT
//  # define M_WIDTH (HEIGHT / 5)
//  # define M_HEIGHT M_WIDTH
// #else
//  # define M_WIDTH 200
//  # define M_HEIGHT 200
// #endif

# define M_WIDTH 200
# define M_HEIGHT 200


# include "utility.h"
# include "MLX42.h"

typedef struct s_cub t_cub;

//-------------------------------------------------
// STRUCTS
//-------------------------------------------------

typedef enum e_sprite_dir
{
	DIR_HORIZONTAL,
	DIR_VERTICAL
}	e_sprite_dir;

typedef struct s_sprite_options
{
	uint32_t		rows;
	uint32_t		cols;
	uint32_t		offset;
	uint16_t		offset_px;
	e_sprite_dir	dir;
}	t_sprite_options;


typedef struct s_sprite
{
	mlx_image_t			**frames;
	uint32_t			frame_w;
	uint32_t			frame_h;
	uint32_t			rows;
	uint32_t			cols;
	uint32_t			idx;
	t_sprite_options	options;
}	t_sprite;

typedef struct s_png_options
{
	int				is_resized;
	uint32_t		resized_px_x;
	uint32_t		resized_px_y;
}	t_png_options;

typedef struct s_asset_manager
{
	t_sprite	*sprite_weapon;
	mlx_image_t	*sprite_door;
	mlx_image_t	*walls[4];
	mlx_image_t	*ceiling;
	mlx_image_t	*floor;
	mlx_image_t	*map;
	mlx_image_t	*m_ray;
	mlx_image_t	*m_wall;
	mlx_image_t	*m_space;
	mlx_image_t	*m_player;
	mlx_image_t	*m_map;
	mlx_image_t	*m_map_bg;
	mlx_image_t	*m_door;
}	t_asset_manager;

//-------------------------------------------------
// MAIN FUCNTIONS
//-------------------------------------------------
void		am_init(t_cub *c);
void		am_free(mlx_t *mlx, t_asset_manager *am);

//-------------------------------------------------
// UTILITY FUNCTIONS
//-------------------------------------------------
mlx_image_t	*am_load_png(t_cub *cub, t_png_options options, const char *path);
mlx_image_t	*am_load_png_ray(t_cub *cub, const char *path);
t_sprite	*am_load_sprite(t_cub *c, t_sprite_options options, t_png_options png_options, char *path);

#endif