/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:10:18 by hitran            #+#    #+#             */
/*   Updated: 2025/01/16 11:05:30 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t error_int(char *message)
{
	ft_printf_fd(2, "Error\n%s\n", message);
	return (EXIT_FAILURE);
}

char	*error_str(char **str, char *message)
{
	ft_printf_fd(2, "Error\n%s\n", message);
	if (str && *str)
	{
		free (*str);
		*str = NULL;
	}
	return (NULL);
}

char	*bad_alloc(char **str)
{
	return (error_str(str, "Memory allocation failed."));
}