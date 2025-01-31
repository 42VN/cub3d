/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:30:06 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 11:03:35 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	clean_map(t_map *map)
{
	if (!map || !map->grid)
		return ;
	if (map->no_fd > 2)
		close (map->no_fd);
	if (map->so_fd > 2)
		close (map->so_fd);
	if (map->we_fd > 2)
		close (map->we_fd);
	if (map->ea_fd > 2)
		close (map->ea_fd);
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
	printf("NO fd: %d\n", map->no_fd);
	printf("SO fd: %d\n", map->so_fd);
	printf("WE fd: %d\n", map->we_fd);
	printf("EA fd: %d\n", map->ea_fd);
	printf("FL color: %d, %d, %d\n", map->f_color >> 16 & 255,
		map->f_color >> 8 & 255, map->f_color & 255);
	printf("CE color: %d, %d, %d\n", map->c_color >> 16 & 255,
		map->c_color >> 8 & 255, map->c_color & 255);
	printf("Map grid: \n");
	i = 0;
	while (map->grid[i])
		printf("%s\n", map->grid[i++]);
}

bool	is_done(t_map *map)
{
	return (map->no_fd && map->so_fd && map->we_fd && map->ea_fd
			&& map->f_color && map->c_color);
}
