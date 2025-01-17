/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:17:25 by hitran            #+#    #+#             */
/*   Updated: 2025/01/17 14:16:05 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_elem_type(char *line)
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

int	parse_color(t_element *element, char *info, int elem_type)
{
	char	**array;

	array = ft_split(info, ',');
	ft_free_strptr(&info);
	if (!array)
		return (error_int("Memory allocation failed."));
	if (ft_array_len(array) != 3)
	{
		ft_free_triptr(&array);
		return (error_int("Invalid elemet format."));
	}
	if (elem_type == F)
		set_color(element->floor, array);
	else
		set_color(element->ceiling, array);
	ft_free_triptr(&array);
	return (EXIT_SUCCESS);
}

int	save_elem_path(t_element *element, char	**splitted_line, int elem_type)
{
	char *info;

	info = ft_strdup(splitted_line[1]);
	ft_free_triptr(&splitted_line);
	if (!info)
		return (error_int("ft_strdup failed."));
	if (elem_type == NO)
		element->no_path = info;
	else if (elem_type == SO)
		element->no_path = info;
	else if (elem_type ==  WE)
		element->no_path = info;
	else if (elem_type == EA)
		element->no_path = info;
	else if (elem_type == F || elem_type == C)
		return (parse_color(element, info, elem_type));
	return (EXIT_SUCCESS);
}

int	parse_element(t_element *element, char **splitted_line, int elem_type)
{


	if ((elem_type == NO && element->no_path)
		|| (elem_type == SO && element->so_path)
		|| (elem_type == WE && element->we_path)
		|| (elem_type == EA && element->ea_path)
		|| (elem_type == F && !element->floor.done)
		|| (elem_type == C && !element->ceiling.done))
		return (error_int("Elements duplicated."));
	if (save_elem_path(element, splitted_line, elem_type) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (element->no_path && element->so_path && element->we_path 
		&& element->ea_path && element->floor.done && element->ceiling.done)
		element->done = 1;
	return (EXIT_SUCCESS);
}

int read_element(t_element *element, char *line)
{
	char	**splitted_line;
	int		size;
	int		elem_type;

	if (!ft_strcmp(line, "\n"))
		return (EXIT_SUCCESS);
	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (error_int("Memory allocation failed."));
	size = ft_array_len(splitted_line);
	if (size != 2) //need to check if the color code of the floor/ceiling is allowed to seperate by spaces
	{
		ft_free_triptr(&splitted_line);
		return (error_int("Invalid elemet format."));
	}
	elem_type = check_elem_type(splitted_line[0]);	
	if (elem_type == -1)
		return (error_int("Invalid elements."));
	return (parse_element(element, splitted_line, elem_type) == EXIT_FAILURE);
}