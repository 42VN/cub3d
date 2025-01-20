/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:38:35 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 15:17:03 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_elements(t_element *elem)
{
	printf("NO path: %s\n", elem->no_path);
	printf("SO path: %s\n", elem->so_path);
	printf("WE path: %s\n", elem->we_path);
	printf("EA path: %s\n", elem->ea_path);
	printf("FL color: %d, %d, %d\n", elem->floor.red,
			elem->floor.green, elem->floor.blue);
	printf("CE color: %d, %d, %d\n", elem->ceiling.red,
			elem->ceiling.green, elem->ceiling.blue);
	if (elem->done)
		printf("Parsing element done\n");
}

void	print_map(t_map *map)
{
	if (!map || !map->arr)
		return ;
	printf("Map: \n");
	while (*(map->arr))
		printf("%s\n", *(map->arr++));
}