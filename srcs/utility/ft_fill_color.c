/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:53:53 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/21 15:36:09 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int	ft_fill_color_int(mlx_image_t *img, int color)
{
	uint32_t	x;
	uint32_t	y;

	if (!img)
		return (0);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, (unsigned int) color);
			++x;
		}
		++y;
	}
	return (1);
}

int	ft_fill_color(mlx_image_t *img, t_color color)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color_int;

	if (!img)
		return (0);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color_int = ft_convert_color(color);
			mlx_put_pixel(img, x, y, color_int);
			++x;
		}
		++y;
	}
	return (1);
}
