/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:46:15 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/24 11:28:27 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	print_elements(t_element *elem)
{
	printf("NO path: %d\n", elem->no_fd);
	printf("SO path: %d\n", elem->so_fd);
	printf("WE path: %d\n", elem->we_fd);
	printf("EA path: %d\n", elem->ea_fd);
	printf("FL color: %d, %d, %d\n", elem->floor.red,
			elem->floor.green, elem->floor.blue);
	printf("CE color: %d, %d, %d\n", elem->ceiling.red,
			elem->ceiling.green, elem->ceiling.blue);
	if (elem->done)
		printf("Parsing done!\n");
}
