/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:19:36 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/29 11:43:59 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d		cub;
	t_map		map;
	t_element	element;
	int		fd;

	if (argc != 2)
		return (ft_error_ret("Usage: ./cub3D [map_path]/[map_name].cub", EXIT_FAILURE));
	ft_bzero(&map, sizeof(map));
	ft_bzero(&element, sizeof(element));
	fd = ft_validate_map_path(argv[1]);
	if (fd < 0)
		return (EXIT_FAILURE);
	if (read_file(&element, &map, fd))
		return (EXIT_FAILURE);
	ft_bzero(&cub, sizeof(cub));
	cub.map = &map;
	cub.element = &element;
	start_minimap(&cub);
	close (fd);
	cub3d_free(&cub);
	return (EXIT_SUCCESS);
}
