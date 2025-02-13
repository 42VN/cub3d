/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:50:53 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/03 14:10:17 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

# include "utility.h"

typedef struct s_player
{
	t_dpoint	current;
	t_dpoint	next;
	double		angle;
	double		speed;
}	t_player;

#endif