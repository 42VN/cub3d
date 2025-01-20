/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:32:36 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 12:02:20 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map_path(char *path)
{
	int		len;
	int		fd;

	if (!path[0] || ft_is_all_white_spaces(path))
		return (error_int(path, "Is an empty path") -2);
	len = ft_strlen(path);
	if (path[len - 4] != '.' || path[len - 3] != 'c'
		|| path[len - 2] != 'u' || path[len - 1] != 'b')
		return (error_int(path, "Not a .cub file") - 2);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_int(path, strerror(errno)) -2);
	return (fd);
}

int	validate_elem_path(char *path)
{
	int		fd;

	if (!path[0] || ft_is_all_white_spaces(path))
		return (error_int(path, "Is an empty path") -2);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_int(path, strerror(errno)) -2);
	return (fd);
}
