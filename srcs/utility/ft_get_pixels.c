/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:29:54 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/27 14:17:41 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

/**
 * Get the pointer to the pixel data at coordinates (x, y) in an image
 */
uint8_t	*ft_get_pixels(mlx_image_t *img, int32_t x, int32_t y)
{
	int32_t	offset;

	if (x < 0 || (uint32_t)x >= img->width
		|| y < 0 || (uint32_t)y >= img->height)
	{
		ft_printf_fd(
			2, "ft_get_pixels: out of bounds [x=%d, y=%d] [w=%d, h=%d]\n",
			x, y, img->width, img->height);
		return (NULL);
	}
	offset = (y * img->width + x) * sizeof(int32_t);
	return (img->pixels + offset);
}
