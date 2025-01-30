/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:30:06 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/30 15:41:30 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
