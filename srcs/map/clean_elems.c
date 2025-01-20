/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:45:01 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 16:10:35 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
