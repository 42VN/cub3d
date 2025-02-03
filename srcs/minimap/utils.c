// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   utils.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
// /*   Updated: 2025/01/31 10:51:47 by hitran           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"

void	exit_cub(t_cub *cub, int32_t stt)
{
	int32_t	index;

	if (!cub)
		return ;
	clean_map(&cub->map);
	// if (cub->m_images)
	// {
	// 	index = -1;
	// 	while (++index < M_TEXTURE_NO)
	// 		if (cub->m_images[index])
	// 			mlx_delete_image(cub->mlx, cub->m_images[index]);
	// 	free(cub->m_images);
	// }
	if (cub->mlx)
		mlx_terminate(cub->mlx);
	exit (stt);
}

void	game_error(t_cub *cub, const char *message)
{
	ft_printf_fd(2, "Error\nGame: %s\n", message);
	exit_cub(cub, EXIT_FAILURE);
}
