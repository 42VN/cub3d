/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:43:51 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/30 15:41:47 by hitran           ###   ########.fr       */
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
