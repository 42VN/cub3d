/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:18:20 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 16:25:24 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:03:55 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 15:46:22 by hitran           ###   ########.fr       */
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
		{
			ft_clean_array(&dest);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static char	**reallocate_map_array(t_map *map)
{
	char	**new_array;

	map->size += BUFFER_SIZE;
	new_array = (char **)ft_calloc(map->size, sizeof(char));
	if (!new_array)
		return (NULL);
	if (array_copy(new_array, map->arr) == EXIT_FAILURE)
		return (NULL);
	ft_clean_array(&map->arr);
	return (new_array);
}

int	allocate_map_array(t_map *map)
{
	if (!map->arr)
	{
		map->arr = (char **)ft_calloc(BUFFER_SIZE, sizeof(char *));
		if (!map->arr)
			return (ft_error_ret("ft_calloc", EXIT_FAILURE));
		map->size = BUFFER_SIZE;
	}
	else
	{
		if (map->max_rows >= map->size)
		{
			map->arr = reallocate_map_array(map);
			if (!map->arr)
				return (ft_error_ret("reallocate", EXIT_FAILURE));
		}
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
	if (allocate_map_array(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map->arr[map->max_rows] = ft_strdup(line);
	if (!map->arr[map->max_rows])
		return (ft_error_ret("ft_strdup", EXIT_FAILURE));
	map->max_rows++;
	return (EXIT_SUCCESS);
}
