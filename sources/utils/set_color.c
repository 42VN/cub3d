/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:04:55 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 09:36:00 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_color(t_color *color, char **array)
{
	color->red = ft_atoi(array[0]);
	color->green = ft_atoi(array[1]);
	color->blue = ft_atoi(array[2]);
	color->done = 1;
	printf("Color: %d, %d, %d\n", color->red, color->green, color->blue); //test
}
