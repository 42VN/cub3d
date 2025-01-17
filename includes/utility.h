/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:37:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/17 16:51:38 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
#define UTILITY_H

# define BUFFER_SIZE 1000

# include "MLX42.h"
# include "libft.h"
# include <stdlib.h>
# include <errno.h>

int		ft_error_ret(char *str, int return_code);
void	ft_error(char *str);
char	*ft_readline(int fd, int size);

#endif