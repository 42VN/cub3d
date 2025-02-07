/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:13:08 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/07 17:19:01 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_img(t_cub *c, mlx_image_t **imgs)
{
	int	i;

	i = 0;
	if (!imgs)
		return ;
	while (imgs[i])
	{
		mlx_delete_image(c->mlx, imgs[i]);
		++i;
	}
	free(imgs);
}
