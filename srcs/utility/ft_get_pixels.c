/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:29:54 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 17:35:57 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

uint8_t	*ft_get_pixels(mlx_image_t *img, int32_t x, int32_t y)
{
	int32_t	offset;

	offset = (y * img->width + x) * sizeof(int32_t);
	return (img->pixels + offset);
}