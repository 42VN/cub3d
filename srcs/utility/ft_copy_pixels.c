/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:25:48 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/04 16:42:58 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

void	ft_copy_pixels(
	mlx_image_t *dst,
	mlx_image_t *src,
	int32_t copy_till_x,
	int32_t copy_till_y)
{
	int32_t		x;
	int32_t		y;
	uint32_t	*src_pixel;
	uint32_t	*dst_pixel;

	y = 0;
	while (y < copy_till_y)
	{
		x = 0;
		while (x  < copy_till_x)
		{
			src_pixel = (uint32_t *) ft_get_pixels(src, x, y);
			dst_pixel = (uint32_t *) ft_get_pixels(dst, x, y);
			*dst_pixel = *src_pixel;
			++x;
		}
		++y;	
	}
}
