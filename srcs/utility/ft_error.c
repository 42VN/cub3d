/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:35:22 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/07 17:56:43 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

char	*ft_error_ret_null(char *str)
{
	ft_error(str);
	return (NULL);
}

int	ft_multi_error_ret(char *str1, char *str2, int return_code)
{
	ft_printf_fd(2, "\n[Error]\n%s: %s\n\n", str1, str2);
	return (return_code);
}

int	ft_error_ret(char *str, int return_code)
{
	ft_error(str);
	return (return_code);
}

void	ft_error(char *str)
{
	if (mlx_errno)
		ft_printf_fd(2, "\n[Error MLX]\n%s: %s\n\n", str, mlx_strerror(mlx_errno));
	else if (errno)
		ft_printf_fd(2, "\n[Error System]\n%s: %s\n\n", str, strerror(errno));
	else
		ft_printf_fd(2, "\n[Error]\n%s\n\n", str);
}
