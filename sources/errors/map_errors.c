/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:10:18 by hitran            #+#    #+#             */
/*   Updated: 2025/01/20 13:02:05 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int error_int(char *message1, char *message2)
{
	ft_printf_fd(2, "Error\n");
	if (message1)
		ft_printf_fd(2, "%s: ", message1);
	ft_printf_fd(2, "%s\n", message2);
	return (EXIT_FAILURE);
}

char	*error_str(char *str, char *message)
{
	ft_printf_fd(2, "Error\n%s\n", message);
	if (str)
		free (str);
	return (NULL);
}

int	read_elem_error(t_element *element, char *line, int fd)
{
	clean_elems(element);
	if (line)
		free(line);
	close(fd);
	return (EXIT_FAILURE);
}

int	read_map_error(t_element *element, t_map *map, char *line, int fd)
{
	clean_elems(element);
	clean_map(map);
	if (line)
		free(line);
	close(fd);
	return (EXIT_FAILURE);
}
