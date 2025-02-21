/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:13:37 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/21 15:13:48 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rays(t_cub *cub)
{
	int	index;

	cub->rays = (t_ray **)ft_calloc(WIDTH, sizeof(t_ray *));
	if (!cub->rays)
		cub3d_error_exit(cub, "init_rays");
	index = -1;
	while (++index < WIDTH)
	{
		cub->rays[index] = (t_ray *)ft_calloc(1, sizeof(t_ray));
		if (!cub->rays[index])
			cub3d_error_exit(cub, "init_rays");
	}
}
