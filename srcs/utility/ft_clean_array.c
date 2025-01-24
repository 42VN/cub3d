/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:23:00 by hitran            #+#    #+#             */
/*   Updated: 2025/01/24 10:39:07 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

void	ft_clean_array(char ***str)
{
	int	i;

	if (!str || !(*str))
		return;
	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		(*str)[i] = NULL;
		i++;
	}
	free(*str);
	*str = NULL;
}
