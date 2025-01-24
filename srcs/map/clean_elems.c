/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:45:01 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/24 11:46:21 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	clean_elems(t_element *element)
{
	if (!element)
		return ;
	if (element->no_fd > 2)
		close (element->no_fd);
	if (element->so_fd > 2)
		close (element->so_fd);
	if (element->we_fd > 2)
		close (element->we_fd);
	if (element->ea_fd > 2)
		close (element->ea_fd);
}
