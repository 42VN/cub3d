/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:36:14 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/04 11:57:45 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_image_to_window(t_cub *cub, mlx_image_t *img,
	int32_t x, int32_t y)
{
	// printf("x = %d, y= %d\n", x , y);
	if (mlx_image_to_window(cub->mlx, img, x, y) < 0)
		cub3d_error_exit(cub, "mlx_image_to_window");
}