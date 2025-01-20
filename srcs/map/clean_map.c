/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:43:51 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 16:35:45 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	clean_map(t_map *map)
{
	if (!map || !map->arr)
		return ;
	ft_clean_array(&map->arr);
}