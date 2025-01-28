/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:46:15 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/28 10:53:53 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	print_elements(t_element *elem)
{
	printf("NO fd: %d\n", elem->no_fd);
	printf("SO fd: %d\n", elem->so_fd);
	printf("WE fd: %d\n", elem->we_fd);
	printf("EA fd: %d\n", elem->ea_fd);
	printf("FL color: %d, %d, %d\n", elem->f_color >> 16 & 255,
		elem->f_color >> 8 & 255, elem->f_color & 255);
	printf("CE color: %d, %d, %d\n", elem->c_color >> 16 & 255,
		elem->c_color >> 8 & 255, elem->c_color & 255);
}
