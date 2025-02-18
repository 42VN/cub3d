/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:46:03 by hitran            #+#    #+#             */
/*   Updated: 2025/02/18 11:38:08 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int	ft_validate_map_path(char *path)
{
	int		len;
	int		fd;

	if (!path[0] || ft_is_all_white_spaces(path))
		return (ft_multi_error_ret(path, "Is an empty path", -1));
	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(path + len - 4, ".cub", 4) != 0)
		return (ft_multi_error_ret(path, "Not a .cub file", -1));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_multi_error_ret(path, strerror(errno), -1));
	return (fd);
}

int	ft_validate_elem_path(char *path)
{
	int		fd;

	if (!path[0] || ft_is_all_white_spaces(path))
		return (ft_multi_error_ret(path, "Is an empty path", -1));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_multi_error_ret(path, strerror(errno), -1));
	return (fd);
}
