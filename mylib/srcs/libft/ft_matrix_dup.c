/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:15:51 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 09:59:40 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	**ft_matrix_dup(char **matrix, int row)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(row + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < row)
	{
		res[i] = ft_strdup(matrix[i]);
		if (!res[i])
		{
			ft_clean_array(&res);
			return (NULL);
		}
	}
	return (res);
}
