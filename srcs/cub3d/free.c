/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:51:23 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/27 10:12:41 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_rays(t_ray ***rays)
{
	int	i;

	if (!rays || !(*rays))
		return ;
	i = 0;
	while (i < WIDTH)
	{
		free((*rays)[i]);
		(*rays)[i] = NULL;
		i++;
	}
	free(*rays);
	*rays = NULL;
}

void	cub3d_free(t_cub *c)
{
	if (c)
	{
		if (c->mlx != NULL)
			mlx_close_window(c->mlx);
		am_free(c->mlx, &c->am);
		clean_rays(&c->rays);
		clean_map(&c->map);
		if (c->mlx)
			mlx_terminate(c->mlx);
	}
}
