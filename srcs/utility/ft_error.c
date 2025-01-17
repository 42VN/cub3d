/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:35:22 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/17 15:23:24 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

int	ft_error_ret(char *str, int return_code)
{
	if (mlx_errno)
	{
		ft_printf_fd(2, "[Error]\ncub3d: %s\n", str);
		ft_printf_fd(2, "Details: %s\n", mlx_strerror(mlx_errno));
	}
	else if (errno)
	{
		ft_printf_fd(2, "[Error]\ncub3d: %s\n", str);
		ft_printf_fd(2, "Details: %s\n", strerror(errno));
	}
	else
		ft_printf_fd(2, "Error: cub3d: %s\n", str);
	return (return_code);
}

void	ft_error(char *str)
{
	if (mlx_errno)
	{
		ft_printf_fd(2, "[Error]\ncub3d: %s\n", str);
		ft_printf_fd(2, "Details: %s\n", mlx_strerror(mlx_errno));
	}
	else if (errno)
	{
		ft_printf_fd(2, "[Error]\ncub3d: %s\n", str);
		ft_printf_fd(2, "Details: %s\n", strerror(errno));
	}
	else
		ft_printf_fd(2, "[Error]\ncub3d: %s\n", str);
}
