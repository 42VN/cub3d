/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:20:33 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/17 14:47:14 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

void ft_set_color(t_color *color, char **array)
{
	color->red = ft_atoi(array[0]);
	color->green = ft_atoi(array[1]);
	color->blue = ft_atoi(array[2]);
	color->done = 1;
	printf("Color: %d, %d, %d\n", color->red, color->green, color->blue); //test
}