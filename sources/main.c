/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 12:54:17 by hitran           ###   ########.fr       */
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
		return (error_int("Usage", "./cub3D [map_path]/[map_name].cub"));
	ft_bzero(&map, sizeof(map));
	ft_bzero(&element, sizeof(element));
	fd = validate_map_path(argv[1]);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (read_file(&element, &map, fd))
		return (EXIT_FAILURE);
	ft_bzero(&cub, sizeof(cub));
	cub.map = &map;
	cub.element = &element;
	// start_cub3d(&cub);
	// exit_cub3d(&cub, EXIT_SUCCESS);
	clean_game(&cub);
	return (EXIT_SUCCESS);
}
