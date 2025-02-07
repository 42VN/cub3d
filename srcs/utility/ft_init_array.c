/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:17:54 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 16:19:45 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

char	**ft_init_array(int row, int col)
{
	char	**array;
	int		index;

	array = (char **)ft_calloc(row + 1, sizeof(char *));
	if (!array)
		return (NULL);
	index = -1;
	while (++index < row)
	{
		array[index] = (char *)ft_calloc(col + 1, sizeof(char));
		if (!array[index])
		{
			ft_clean_array(&array);
			return (NULL);
		}
		ft_memset(array[index], ' ', col);
	}
	return (array);
}
