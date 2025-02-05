/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_load_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:50:43 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/05 16:45:20 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// offset_x = (options.dir == DIR_HORIZONTAL) ? s->frame_w * i : 0;
// offset_y = (options.dir == DIR_VERTICAL) ? s->frame_h * i : 0;

static void calc_offset(t_sprite *s, int *offset_x, int *offset_y, int i)
{
	int	offset;

	offset = s->options.offset_px;
	if (s->options.dir == DIR_HORIZONTAL)
	{
		*offset_x = (s->frame_w * i) + offset;
		*offset_y = 0;
	}
	if (s->options.dir == DIR_VERTICAL)
	{
		*offset_x = 0;
		*offset_y = (s->frame_h * i) + offset;
	}
	// printf("Offset %d: x[%d], y[%d], offset_px[%d]\n",i, *offset_x, *offset_y, s->options.offset_px);
	// printf("Frame %d: w[%d], h[%d]\n", s->fra);

}

static void	init_frames(
	t_cub *c,
	mlx_image_t *img,
	t_sprite *s,
	t_sprite_options options)
{
	uint8_t *const	original = img->pixels;
	int				i;
	int				frame_count;
	int				offset;
	int				offset_x;
	int				offset_y;

	frame_count = (options.dir == DIR_HORIZONTAL) ? options.cols : options.rows;
	// printf("Frame: w[%d], h[%d]\n", s->frame_w, s->frame_h);
	for (i = 0; i < frame_count; i++)
	{
		s->frames[i] = mlx_new_image(c->mlx, s->frame_w, s->frame_h);
		if (!s->frames[i])
			cub3d_error_exit(c, "init_sprite: init_frames: mlx_new_image");
		calc_offset(s, &offset_x, &offset, i);
		img->pixels = ft_get_pixels(img, offset_x, offset_y);
		ft_copy_pixels(s->frames[i], img, s->frame_w, s->frame_h);
		img->pixels = original; // Restore original pointer
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
	if (options.dir == DIR_HORIZONTAL)
	{
		s->options.offset_px = (image->width / options.cols) * (options.offset);
		s->frame_w = (image->width / options.cols) ;
		s->frame_h = (image->height / options.rows);
		frame_count = options.cols;
	}
	else if (options.dir == DIR_VERTICAL)
	{
		s->options.offset_px = (image->height / options.rows) * (options.offset);
		s->frame_w = (image->width / options.cols);
		s->frame_h = (image->height / options.rows);
		frame_count = options.rows;
	}
	s->frames = (mlx_image_t **)ft_calloc(frame_count + 1, sizeof(mlx_image_t *));
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
	res->options = options;
	init_sprite(c, res, options, img);
	return (res);
}
