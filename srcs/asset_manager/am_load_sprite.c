/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:50:43 by ktieu             #+#    #+#             */
/*   Updated: 2025/01/31 18:09:33 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	analyze_frame(
	t_sprite *s,
	t_sprite_options options,
	int *offset)
{
	int	frame_count;

	*offset = 0;
	frame_count = 0;
	if (options.dir == DIR_HORIZONTAL)
	{
		frame_count = options.cols;
		*offset = s->frame_w;
	}
	else if (options.dir == DIR_VERTICAL)
	{
		frame_count = options.rows;
		*offset = s->frame_h;
	}
	return (frame_count);
}

static void	init_frames(
	t_cub *c,
	mlx_image_t *img,
	t_sprite *s,
	t_sprite_options options)
{
	uint8_t *const	original = img->pixels;
	int				i;
	int				offset;
	int				frame_count;

	i = 0;
	frame_count = analyze_frame(s, options, &offset);
	while (i < frame_count)
	{
		s->frames[i] = mlx_new_image(c->mlx, s->frame_w, s->frame_h);
		if (!s->frames[i])
			cub3d_error_exit(c, "init_sprite: init_frames: mlx_new_image");
		if (options.dir == DIR_HORIZONTAL)
		{
			img->pixels = ft_get_pixels(img, s->frame_w + offset, s->frame_h);
			ft_copy_pixels(s->frames[i], img, s->frame_w + offset, s->frame_h);
		}
		else if (options.dir == DIR_VERTICAL)
		{
			img->pixels = ft_get_pixels(img, s->frame_w, s->frame_h + offset);
			ft_copy_pixels(s->frames[i], img, s->frame_w, s->frame_h + offset);
		}
		img->pixels = original;
		++i;
	}
}

static t_sprite	*init_sprite(
	t_cub *c,
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
		s->frames = (mlx_image_t **)ft_calloc(options.cols + 1, sizeof(mlx_image_t *));
	}
	else if (options.dir == DIR_VERTICAL)
	{
		frame_count = options.rows;
		s->frames = (mlx_image_t **)ft_calloc(options.rows + 1, sizeof(mlx_image_t *));
	}
	if (!s->frames)
		return (0);
	init_frames(c, image, s, options);
	return (s);
}	

t_sprite	*am_load_sprite(
	t_cub *c,
	t_sprite_options options,
	t_png_options png_options,
	char *path)
{
	mlx_image_t	*img;
	t_sprite	*res;

	if (!c || !c->mlx || !path)
		cub3d_error_exit(c, "am_load_sprite: Invalid parameter(s)");
	img = am_load_png(c, png_options, path);
	if (!img)
	{
		ft_error("am_load_sprite: am_load_png");
		return (NULL);
	}
	res = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!res)
	{
		mlx_delete_image(c->mlx, img);
		ft_error("am_load_sprite: ft_calloc");
		return (NULL);
	}
	init_sprite(c, res, options, img);
	return (res);
	
}
