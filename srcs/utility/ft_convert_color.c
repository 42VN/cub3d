/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:57:14 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/22 18:06:14 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

uint32_t	ft_convert_color(t_color color)
{
	return (color.transparent << 24 | color.red << 16 | color.green << 8 | color.blue);
}
