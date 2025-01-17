/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:10:18 by hitran            #+#    #+#             */
/*   Updated: 2025/01/17 13:15:57 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int error_int(char *message)
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

int	read_elem_error(t_element *element, char *line, int fd)
{
	if (element->no_path)
		ft_free_strptr(&element->no_path);
	if (element->so_path)
		ft_free_strptr(&element->so_path);
	if (element->we_path)
		ft_free_strptr(&element->we_path);
	if (element->ea_path)
		ft_free_strptr(&element->ea_path);
	if (line)
		ft_free_strptr(&line);
	close(fd);
	return (EXIT_FAILURE);
}
