/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:37:09 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/27 09:47:46 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
#define UTILITY_H


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif 

# include "MLX42.h"
# include "libft.h"
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "fcntl.h"

typedef struct s_color
{
	uint32_t	transparent;
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	int			done;
}	t_color;

//----------------------------------------------
// ERROR
//----------------------------------------------
char		*ft_error_ret_null(char *str);
void		ft_error(char *str);
int			ft_error_ret(char *str, int return_code);
int			ft_multi_error_ret(char *str1, char *str2, int return_code);

//----------------------------------------------
// PATH
//----------------------------------------------
int			ft_validate_map_path(char *path);
int			ft_validate_elem_path(char *path);

//----------------------------------------------
// COLOR
//----------------------------------------------
int 		ft_set_color(t_color *color, char **array);
void		ft_fill_color(mlx_image_t *img ,t_color color);
uint32_t	ft_convert_color(t_color color);
//----------------------------------------------
// UTILITY
//----------------------------------------------
char		*ft_readline(int fd, int *eof, int size);
int			ft_is_all_white_spaces(char *s);
int			ft_array_len(char **array);
void		ft_clean_array(char ***str);
#endif