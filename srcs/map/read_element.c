/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/02/19 14:18:26 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	check_elem_type(char *line)
{
	if (!ft_strcmp(line, "NO"))
		return (NO);
	else if (!ft_strcmp(line, "SO"))
		return (SO);
	else if (!ft_strcmp(line, "WE"))
		return (WE);
	else if (!ft_strcmp(line, "EA"))
		return (EA);
	else if (!ft_strcmp(line, "F"))
		return (F);
	else if (!ft_strcmp(line, "C"))
		return (C);
	else
		return (-1);
}

static int	parse_color(t_map *map, char **splitted_line, int elem_type)
{
	char	**array;

	array = ft_split(splitted_line[1], ',');
	if (!array)
		return (ft_error_ret("ft_split failed.", EXIT_FAILURE));
	if (ft_array_len(array) != 3
		|| splitted_line[1][ft_strlen(splitted_line[1]) - 1] == ',')
	{
		ft_clean_array(&array);
		return (ft_error_ret("Invalid color format.", EXIT_FAILURE));
	}
	if ((elem_type == F
			&& ft_set_color(&map->f_color, array) == EXIT_FAILURE)
		|| (elem_type == C
			&& ft_set_color(&map->c_color, array) == EXIT_FAILURE))
	{
		ft_clean_array(&array);
		return (EXIT_FAILURE);
	}
	ft_clean_array(&array);
	return (EXIT_SUCCESS);
}

static int	save_element(t_map *map, char	**splitted_line, int elem_type)
{
	if (elem_type == F || elem_type == C)
		return (parse_color(map, splitted_line, elem_type));
	if (ft_validate_png_path(splitted_line[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (elem_type == NO)
		map->no_path = ft_strdup(splitted_line[1]);
	else if (elem_type == SO)
		map->so_path = ft_strdup(splitted_line[1]);
	else if (elem_type == WE)
		map->we_path = ft_strdup(splitted_line[1]);
	else if (elem_type == EA)
		map->ea_path = ft_strdup(splitted_line[1]);
	return (EXIT_SUCCESS);
}

static int	parse_element(t_map *map, char **splitted_line,
			int elem_type)
{
	if (is_done(map))
	{
		ft_clean_array(&splitted_line);
		return (ft_error_ret("Elements duplicated.", EXIT_FAILURE));
	}
	if (save_element(map, splitted_line, elem_type) == EXIT_FAILURE)
	{
		ft_clean_array(&splitted_line);
		return (EXIT_FAILURE);
	}
	ft_clean_array(&splitted_line);
	return (EXIT_SUCCESS);
}

int	read_element(t_map *map, char *line)
{
	char	**splitted_line;
	int		size;
	int		elem_type;

	if (!line[0])
		return (EXIT_SUCCESS);
	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (ft_error_ret("ft_split failed.", EXIT_FAILURE));
	size = ft_array_len(splitted_line);
	if (size != 2)
	{
		ft_clean_array(&splitted_line);
		return (ft_error_ret("Invalid element format.", EXIT_FAILURE));
	}
	elem_type = check_elem_type(splitted_line[0]);
	if (elem_type == -1)
	{
		ft_clean_array(&splitted_line);
		return (ft_error_ret("Invalid element types.", EXIT_FAILURE));
	}
	return (parse_element(map, splitted_line, elem_type));
}
