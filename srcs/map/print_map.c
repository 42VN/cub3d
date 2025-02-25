/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:56:06 by hitran            #+#    #+#             */
/*   Updated: 2025/02/25 09:56:41 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	print_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	printf("NO path: %s\n", map->no_path);
	printf("SO path: %s\n", map->so_path);
	printf("WE path: %s\n", map->we_path);
	printf("EA path: %s\n", map->ea_path);
	printf("Floor color: %d, %d, %d\n", map->f_color >> 16 & 255,
		map->f_color >> 8 & 255, map->f_color & 255);
	printf("Ceiling color: %d, %d, %d\n", map->c_color >> 16 & 255,
		map->c_color >> 8 & 255, map->c_color & 255);
	printf("Map grid: \n");
	i = 0;
	while (map->grid[i])
		printf("[%s]\n", map->grid[i++]);
}
