/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:15:03 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/24 11:45:13 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	read_map_error(t_element *element, t_map *map, char *line, int fd)
{
	clean_elems(element);
	clean_map(map);
	if (line)
		free(line);
	close(fd);
	return (EXIT_FAILURE);
}
