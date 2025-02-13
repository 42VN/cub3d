/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:48:01 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/13 05:38:00 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

/**
 * Delete a memory representing a section of pixels
 * 
 * Description:
 * -	A pixel is represented as 4 bytes in memory 
 * -	pos: 			the current position in the memory
 * -	start_px + pos:	the pointer to the (offset + pos)
 */
void	ft_del_pixels(
	uint8_t *start_px,
	uint32_t img_width,
	int32_t offset_x,
	int32_t offset_y)
{
	int32_t		x;
	int32_t		y;
	uint32_t	pos;
	uint32_t	*px;

	y = 0;
	while (y < offset_y)
	{
		x = 0;
		while (x < offset_x)
		{
			pos = (y * img_width + x) * sizeof(int32_t);
			px = (uint32_t *)(start_px + pos);
			*px = 0;
			++x;
		}
		++y;
	}
}
