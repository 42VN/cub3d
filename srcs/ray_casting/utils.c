/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:55:34 by hitran            #+#    #+#             */
/*   Updated: 2025/02/03 14:06:19 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rescale(double angle)
{
	if (angle < 0)
		return (angle + 2 * PI);
	else if (angle >= 2 * PI)
		return (angle - 2 * PI);
	else
		return (angle);
}
