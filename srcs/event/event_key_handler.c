/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 07:28:20 by ktieu             #+#    #+#             */
/*   Updated: 2025/02/13 15:35:07 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_beams(t_cub *cub)
{
	mlx_delete_image(cub->mlx, cub->am.m_ray);
	cub->am.m_ray = am_load_png_ray(cub, M_RAY);
	draw_rays(cub);
}

static int	is_movable(char **grid, double x, double y)
{
	int	row1;
	int	col1;
	int	row2;
	int	col2;

	row1 = (int) (y + CELL_PX/3 + 1) / CELL_PX;
	col1 = (int) (x + CELL_PX/3 + 1) / CELL_PX;
	row2 = (int) (y + 2*CELL_PX/3) / CELL_PX;
	col2 = (int) (x + 2*CELL_PX/3) / CELL_PX;
	if (grid[row1][col1] == '0' && grid[row2][col1] == '0' && grid[row1][col2] == '0' && grid[row2][col2] == '0')
		return (1);
	return (0);
}


static void	move_player(t_cub *cub)
{
	cub->player.current = (t_dpoint){cub->player.next.x, cub->player.next.y};
	update_beams(cub);
	// cub->mini[PLAYER]->instances[0].x = cub->player.current.x;
	// cub->mini[PLAYER]->instances[0].y = cub->player.current.y;
}

static t_dpoint	next_point(t_dpoint cur, double angle, keys_t key)
{
	t_dpoint	next;

	next = (t_dpoint){cur.x, cur.y};
	if (key == MLX_KEY_W)
		next = (t_dpoint){cur.x + cos(angle), cur.y - sin(angle)};
	else if (key == MLX_KEY_S)
		next = (t_dpoint){cur.x - cos(angle), cur.y + sin(angle)};
	else if (key == MLX_KEY_A)
		next = (t_dpoint){cur.x + cos(angle + PI / 2),
							cur.y - sin(angle + PI / 2)};
	else if (key == MLX_KEY_D)
		next = (t_dpoint){cur.x + cos(angle + 3 * PI / 2),
							cur.y - sin(angle + 3 * PI / 2)};
	return (next);
}


void	event_key_handler(mlx_key_data_t keydata, void *data)
{
	t_cub	*c;

	c = (t_cub *)data;
	t_dpoint	cur;

	cur = c->player.current;
	c->player.next = (t_dpoint){cur.x, cur.y};
	if (keydata.key == MLX_KEY_ESCAPE)
		cub3d_exit(c, EXIT_SUCCESS);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		c->player.next = next_point(cur, c->player.angle, keydata.key);
	else if (keydata.key == MLX_KEY_LEFT)
		c->player.angle = rescale(c->player.angle + PI / 36);
	else if (keydata.key == MLX_KEY_RIGHT)
		c->player.angle = rescale(c->player.angle - PI / 36);
	else
		return ;
	if (is_movable(c->map.grid, c->player.next.x, c->player.next.y))
		// c->player.current = (t_dpoint){c->player.next.x, c->player.next.y};
		move_player(c);
}