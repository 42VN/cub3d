/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:25:48 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 17:29:36 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

void	ft_copy_pixels(
	mlx_image_t *dst,
	mlx_image_t *src,
	int32_t offset_x,
	int32_t offset_y)
{
	int32_t	x;
	int32_t	y;

	y = 0;
	while (y < offset_y)
	{
		x = 0;
		while (x  < offset_x)
		{
			++x;
		}
		++y;	
	}
}