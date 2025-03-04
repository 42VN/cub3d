/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:19:36 by ktieu             #+#    #+#             */
/*   Updated: 2025/03/04 14:49:01 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;
	int		fd;

	if (argc != 2)
		return (ft_error_ret("Usage: ./cub3D [map_path]/[map_name].cub",
				EXIT_FAILURE));
	ft_bzero(&cub, sizeof(cub));
	fd = ft_validate_map_path(argv[1]);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (read_map(&cub, fd))
		return (EXIT_FAILURE);
	cub.map.width = cub.map.max_cols * M_PX;
	cub.map.height = cub.map.max_rows * M_PX;
	close(fd);
	cub3d_init(&cub);
	mlx_loop(cub.mlx);
	cub3d_free(&cub);
	return (EXIT_SUCCESS);
}
