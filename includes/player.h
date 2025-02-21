/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:50:53 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/21 14:22:12 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

# include "utility.h"

typedef struct s_player
{
    t_dpoint	prev;
	t_dpoint	current;
	double		angle;
	double		speed;
	int			is_attacking;
}	t_player;

typedef struct s_door
{
	int32_t			x;
	int32_t			y;
}	t_door;

#endif