/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_png.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:07:50 by hitran            #+#    #+#             */
/*   Updated: 2025/02/25 14:08:11 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
* Magic number of a PNG file: 89 50 4E 47 0D 0A 1A 0A (8bytes)
*/
static int	check_magic_number(char *path)
{
	int				fd;
	unsigned char	header[8];

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error_ret(path, EXIT_FAILURE));
	if (read(fd, header, 8) != 8 || header[0] != 0x89 || header[1] != 0x50
		|| header[2] != 0x4E || header[3] != 0x47 || header[4] != 0x0D
		|| header[5] != 0x0A || header[6] != 0x1A || header[7] != 0x0A)
	{
		close(fd);
		return (ft_multi_error_ret(path, "Not a valid PNG file", EXIT_FAILURE));
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	validate_png(char *path)
{
	int	len;

	if (!path[0] || ft_is_all_white_spaces(path))
		return (ft_multi_error_ret(path, "Is an empty path", EXIT_FAILURE));
	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".png", 4) != 0)
		return (ft_multi_error_ret(path, "Not a .png file", EXIT_FAILURE));
	if (access(path, F_OK) == -1)
		return (ft_error_ret(path, EXIT_FAILURE));
	return (check_magic_number(path));
}
