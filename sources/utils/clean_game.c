/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:49:36 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 12:57:10 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_elems(t_element *element)
{
	if (!element)
		return ;
	if (element->no_path)
		free(element->no_path);
	if (element->so_path)
		free(element->so_path);
	if (element->we_path)
		free(element->we_path);
	if (element->ea_path)
		free(element->ea_path);
}

void	clean_map(t_map *map)
{
	if (!map || !map->arr)
		return ;
	ft_clean_array(&map->arr);
}

void	clean_game(t_cub3d *cub)
{
	if (!cub)
		return ;
	clean_elems(cub->element);
	clean_map(cub->map);
}
