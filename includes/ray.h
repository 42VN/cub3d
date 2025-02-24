/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:50:53 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/24 14:59:22 by hitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
#define RAY_H

# include "utility.h"

typedef enum e_hit_dir
{
	HORIZONTAL,
	VERTICAL
}	t_hit_dir;

typedef struct s_ray
{
	t_dpoint	start;
	t_dpoint	end;
	t_point		hit;
	t_dpoint	dir;
	double		angle;
	double		distance;
	t_hit_dir	hit_direction;
	mlx_image_t	*image;
	int			im_position;
}	t_ray;

double	rescale(double angle);
void	ray_casting(t_cub *cub);
void	find_hit_point(t_ray *ray, t_cub *cub);
void	process_ray_hit(t_ray *ray, t_cub *cub);

#endif