/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:26 by hitran            #+#    #+#             */
/*   Updated: 2025/01/24 14:20:20 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_direction	get_direction(char c)
{
	if (c == 'N')
		return (N);
	else if (c == 'S')
		return (S);
	else if (c == 'W')
		return (W);
	else if (c == 'E')
		return (E);
	return (O);
}

static int	validate_characters(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" 01NSEW", line[i]))
			return (ft_multi_error_ret(line, "Map contains invalid characters",
					EXIT_FAILURE));
		else if (ft_strchr("NSEW", line[i]))
		{
			if  (map->start.direction > 0)
				return (ft_error_ret("Payer duplicated.", EXIT_FAILURE));
			map->start.col = i;
			map->start.row = map->max_rows;
			map->start.direction = get_direction(line[i]);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	validate_map(t_element *element, t_map *map, int fd)
{
	int	i;

	i = 0;
	while (map && map->arr && map->arr[i])
	{
		if (validate_characters(map, map->arr[i]) == EXIT_FAILURE)
			return (map_error(element, map, NULL, fd));
		i++;
	}
	return (EXIT_SUCCESS);
}
