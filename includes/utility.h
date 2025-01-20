/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:37:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 16:21:30 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
#define UTILITY_H


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif 

# include "MLX42.h"
# include "libft.h"
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "fcntl.h"

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	done;
}	t_color;

char	*ft_error_str_ret(char *str, char *message);
void	ft_error(char *str);
int		ft_error_ret(char *str, int return_code);
int		ft_multi_error_ret(char *str1, char *str2, int return_code);

char	*ft_readline(int fd, int *eof, int size);

int		ft_validate_map_path(char *path);
int		ft_validate_elem_path(char *path);

void 	ft_set_color(t_color *color, char **array);

int		ft_is_all_white_spaces(char *s);
int		ft_array_len(char **array);
void	ft_clean_array(char ***str);
#endif