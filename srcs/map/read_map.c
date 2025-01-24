/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:39:26 by hitran            #+#    #+#             */
/*   Updated: 2025/01/24 10:24:44 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	array_copy(char **dest, char **source)
{
	int	i;

	i = 0;
	while (source && source[i])
	{
		dest[i] = ft_strdup(source[i]);
		if (!dest[i])
			return (ft_error_ret("Map copying: ft_strdup failed.", EXIT_FAILURE));
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	reallocate(t_map *map)
{
	char	**new_array;

	if (map->max_rows >= map->size)
	{
		map->size += BUFFER_SIZE;
		new_array = (char **)ft_calloc(map->size, sizeof(char *));
		if (!new_array)
			return (EXIT_FAILURE);
		if (array_copy(new_array, map->arr) == EXIT_FAILURE)
		{
			ft_clean_array(&new_array);
			return (EXIT_FAILURE);
		}
		ft_clean_array(&map->arr);
		map->arr = new_array;
	}
	return (EXIT_SUCCESS);
}

int	read_map(t_map *map, char *line)
{
	int	len;

	if (!map || !line)
		return (EXIT_FAILURE);
	len = ft_strlen(line);
	if (len > map->max_cols)
		map->max_cols = len;
	if (reallocate(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map->arr[map->max_rows] = ft_strdup(line);
	if (!map->arr[map->max_rows])
		return (ft_error_ret("Map reading: ft_strdup failed.", EXIT_FAILURE));
	map->max_rows++;
	return (EXIT_SUCCESS);
}
