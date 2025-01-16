/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/16 10:29:33 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	file_error(int32_t fd, char *path, char *message)
{
	if (fd > 2)
		close(fd);
	ft_printf_fd(2, "Error\n%s: %s\n", path, message);
	exit (EXIT_FAILURE);
}

static int32_t	validate_path(char *path)
{
	int32_t		len;
	int32_t		fd;

	if (!path[0] || ft_is_all_white_spaces(path))
		file_error(0, path, "Is an empty path");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		file_error(0, path, strerror(errno));
	len = ft_strlen(path);
	if (path[len - 4] != '.' || path[len - 3] != 'c'
		|| path[len - 2] != 'u' || path[len - 1] != 'b')
		file_error(fd, path, "Not a .cub file");
	return (fd);
}

int32_t	main(int argc, char **argv)
{
	// t_cub3d		cub;
	t_map		map;
	t_element	element;
	int32_t		fd;

	if (argc != 2)
	{
		ft_printf_fd(2, "Error\nUsage: ./cub3D [map_path]/[map_name].cub");
		return (1);
	}
	ft_bzero(&map, sizeof(map));
	fd = validate_path(argv[1]);
	if (read_map(&element, &map, fd))
		return (EXIT_FAILURE);
	// ft_bzero(&cub, sizeof(cub));
	// cub.map = &map;
	// start_cub3d(&cub);
	// exit_cub3d(&cub, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
