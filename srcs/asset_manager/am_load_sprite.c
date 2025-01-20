/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:50:43 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/20 17:00:36 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asset_manager.h"

static int	alloc_sprite_frames(t_sprite *s, uint32_t frame_count)
{
	int	i;

	i = 0;
	while (i < frame_count)
	{
		s->frames[i] = ft_calloc(1, sizeof(mlx_image_t *));
		if (!s->frames[i])
			return (0);
		++i;
	}
	return (1);
}

static t_sprite	*init_sprite(
	t_sprite *s,
	t_sprite_options options,
	mlx_image_t *image
)
{
	uint32_t	frame_count;
	
	s->rows = options.rows;
	s->cols = options.cols;
	s->frame_w = image->width / options.cols;
	s->frame_h = image->height / options.rows;
	if (options.dir == DIR_HORIZONTAL)
	{
		frame_count = options.cols;
		s->frames = (mlx_image_t **)ft_calloc(options.cols, sizeof(mlx_image_t *));
	}
	else if (options.dir == DIR_VERTICAL)
	{
		frame_count = options.rows;
		s->frames = (mlx_image_t **)ft_calloc(options.rows, sizeof(mlx_image_t *));
	}
	if (!s->frames)
		return (0);
	alloc_sprite_frames(s, frame_count);
	return (s);
}	

t_sprite	*am_load_sprite(mlx_t *mlx, t_sprite_options options, char *path)
{
	mlx_image_t	*img;
	t_sprite	*res;

	img = am_load_png(mlx, path);
	if (!img)
	{
		ft_error("am_load_sprite: am_load_png");
		return (NULL);
	}
	res = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!res)
	{
		mlx_delete_image(mlx, img);
		ft_error("am_load_sprite: ft_calloc");
		return (NULL);
	}
	return (res);
	
}
