/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/29 12:34:12 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_cub3d(t_cub3d *cub, int32_t stt)
{
	int32_t	index;

	if (!cub)
		return ;
	clean_elems(cub->element);
	clean_map(cub->map);
	if (cub->mini_images)
	{
		index = -1;
		while (++index < M_TEXTURE_NO)
			if (cub->mini_images[index])
				mlx_delete_image(cub->mlx, cub->mini_images[index]);
		free(cub->mini_images);
	}
	if (cub->mlx)
		mlx_terminate(cub->mlx);
	exit (stt);
}

void	game_error(t_cub3d *cub, const char *message)
{
	ft_printf_fd(2, "Error\nGame: %s\n", message);
	exit_cub3d(cub, EXIT_FAILURE);
}
