/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:30:06 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/19 13:34:32 by hitran           ###   ########.fr       */
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

void	print_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	printf("NO path: %s\n", map->no_path);
	printf("SO path: %s\n", map->so_path);
	printf("WE path: %s\n", map->we_path);
	printf("EA path: %s\n", map->ea_path);
	printf("FL color: %d, %d, %d\n", map->f_color >> 16 & 255,
		map->f_color >> 8 & 255, map->f_color & 255);
	printf("CE color: %d, %d, %d\n", map->c_color >> 16 & 255,
		map->c_color >> 8 & 255, map->c_color & 255);
	// printf("FL color: %d, CE color: %d\n", map->f_color, map->c_color);
	// printf("Map grid: \n");
	i = 0;
	while (map->grid[i])
		printf("[%s]\n", map->grid[i++]);
}

bool	is_done(t_map *map)
{
	return (map->no_path && map->so_path && map->we_path && map->ea_path
			&& map->f_color && map->c_color);
}