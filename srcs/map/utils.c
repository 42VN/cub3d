/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:54:24 by hitran            #+#    #+#             */
/*   Updated: 2025/03/04 14:27:20 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	clean_map(t_map *map)
{
	if (!map || !map->grid)
		return ;
	if (map->no_path)
		ft_free_null(&map->no_path);
	if (map->so_path)
		ft_free_null(&map->so_path);
	if (map->we_path)
		ft_free_null(&map->we_path);
	if (map->ea_path)
		ft_free_null(&map->ea_path);
	if (map->grid)
		ft_clean_array(&map->grid);
}

int	map_error(t_map *map, char *line, int fd)
{
	clean_map(map);
	if (line)
		free(line);
	close(fd);
	return (EXIT_FAILURE);
}

int	count_commas(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == ',')
			count++;
		str++;
	}
	return (count);
}
