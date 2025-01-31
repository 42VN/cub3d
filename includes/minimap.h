/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:15:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 11:17:53 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "cub3d.h"

# define MPX 32
# define M_TEXTURE_NO	3

# define M_SPACE	"./assets/textures/mini_space.png"
# define M_WALL		"./assets/textures/mini_wall.png"
# define M_PLAYER	"./assets/textures/mini_player.png"

// minimap
void	start_minimap(t_cub *cub);
void	display_minimap(t_cub *cub, int32_t row, int32_t col);

// UTILS //
void	exit_cub(t_cub *cub, int32_t stt);
void	game_error(t_cub *cub, const char *message);

#endif