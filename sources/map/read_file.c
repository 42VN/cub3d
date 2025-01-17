/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/17 13:21:17 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_file(t_element *element, t_map *map, int fd)
{
	char	*line;

	while (1)
	{
		line = read_line(fd, BUFFER_SIZE);
		if (!line)
			return (EXIT_FAILURE);
		if (!element->done)
		{
			if (read_element(element, line) == EXIT_FAILURE)
				return (read_elem_error(element, line, fd));
		}
		else
		{
			(void)map;
			// if (read_map(element, line) == EXIT_FAILURE)
			// 	return (read_map_error(element, map, line, fd));
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}
