/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:47:41 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/13 07:38:49 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Function to free and exit the game.
 * If there is no error, pass in NULL for str
 */
void	cub3d_error_exit(t_cub *c, char *str)
{
	if (str)
		ft_error(str);
	cub3d_free(c);
	exit(EXIT_FAILURE);
}

void	cub3d_exit(t_cub *c, int status)
{
	cub3d_free(c);
	exit(status);
}
