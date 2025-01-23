/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:50:12 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/23 13:58:16 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d		cub;

	if (argc != 2)
		return (ft_error_ret("Usage: ./cub3D [map_path]/[map_name].cub", EXIT_FAILURE));
	cub3d_init(&cub);
	mlx_loop(cub.mlx);
	cub3d_free(&cub);
	return (EXIT_SUCCESS);
}