// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   start_cub.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/08/20 00:30:53 by hitran            #+#    #+#             */
// /*   Updated: 2025/01/29 11:00:00 by hitran           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"

static void	update_beams(t_cub *cub)
{
	mlx_delete_image(cub->mlx, cub->mini[RAY]);
	cub->mini[RAY] = png_to_ray(cub, M_RAY);
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
	cub->mini[PLAYER]->instances[0].x = cub->player.current.x;
	cub->mini[PLAYER]->instances[0].y = cub->player.current.y;
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

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub		*cub;
	t_dpoint	cur;

	cub = (t_cub *)param;
	cur = cub->player.current;
	cub->player.next = (t_dpoint){cur.x, cur.y};
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_cub(cub, EXIT_SUCCESS);
	else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		cub->player.next = next_point(cur, cub->player.angle, keydata.key);
	else if (keydata.key == MLX_KEY_LEFT)
		cub->player.angle = rescale(cub->player.angle + PI / 36);
	else if (keydata.key == MLX_KEY_RIGHT)
		cub->player.angle = rescale(cub->player.angle - PI / 36);
	else
		return ;
	if (is_movable(cub->map.grid, cub->player.next.x, cub->player.next.y))
		move_player(cub);
}

static void	loop_hook(void *param)
{
	t_cub		*cub;

	cub = (t_cub *)param;
	ray_casting(cub);
}

static void	close_hook(void *param)
{
	exit_cub((t_cub *)param, EXIT_SUCCESS);
}

static void	init_hooks(t_cub *cub)
{
	if (mlx_loop_hook(cub->mlx, loop_hook, cub) == false)
		game_error(cub, strerror(errno));
	mlx_close_hook(cub->mlx, close_hook, cub);
}

void	start_minimap(t_cub *cub)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	cub->mlx = mlx_init(WIDTH, HEIGHT, "minimap", true);
	if (!cub->mlx)
		game_error(cub, mlx_strerror(mlx_errno));

	cub->rays = (t_ray *)ft_calloc(WIDTH, sizeof(t_ray));
	// cub->rays = (t_ray *)ft_calloc(19, sizeof(t_ray)); //5 degree * 18 = 90
	if (cub->rays == NULL)
		game_error(cub, strerror(errno));

	display_minimap(cub, -1, -1);
	ray_casting(cub);
	draw_rays(cub);
	mlx_key_hook(cub->mlx, key_hook, cub);
	mlx_loop_hook(cub->mlx, loop_hook, cub);
	mlx_close_hook(cub->mlx, close_hook, cub);
	mlx_loop(cub->mlx);
	exit_cub(cub, EXIT_SUCCESS);
}
