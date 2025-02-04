/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:29:54 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/04 20:52:31 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

/**
 * Get the pointer to the pixel data at coordinates (x, y) in an image
 */
uint8_t	*ft_get_pixels(mlx_image_t *img, int32_t x, int32_t y)
{
	int32_t	offset;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        ft_printf_fd(2, "ft_get_pixels: out of bounds [x=%d, y=%d]\n", x, y);
        return (NULL);
    }
	offset = (y * img->width + x) * sizeof(int32_t);
	return (img->pixels + offset);
}