/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:40:47 by hitran            #+#    #+#             */
/*   Updated: 2025/01/28 10:56:25 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int	get_color(const char *str)
{
	int	number;

	if (!str[0] || ft_strlen(str) > 3)
		return (-1);
	number = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		number = number * 10 + *str++ - '0';
	}
	if (number > 255)
		return (-1);
	return (number);
}

int	ft_set_color(int *color, char **array)
{
	int	red;
	int	green;
	int	blue;

	red = get_color(array[0]);
	green = get_color(array[1]);
	blue = get_color(array[2]);
	if (red == -1 || green == -1 || blue == -1)
		return (ft_error_ret("Invalid color format.", EXIT_FAILURE));
	*color = (1 << 24) + (red << 16) + (green << 8) + blue;
	return (EXIT_SUCCESS);
}
