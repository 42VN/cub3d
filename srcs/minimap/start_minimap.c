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

int	is_movable(char **grid, double x, double y)
{
	int	row;
	int	col;

	row = (int) (y + CELL_PX/2) / CELL_PX;
	col = (int) (x + CELL_PX/2) / CELL_PX;
	// printf("x = %f, y = %f, row = %d, col = %d, map = %c\n", x, y, row, col, grid[row][col]);
	if (grid[row][col] == '0')
		return (1);
	return (0);
}

void	move_player(t_cub *cub)
{
	cub->player.current = (t_dpoint){cub->player.next.x, cub->player.next.y};
	update_beams(cub);
	cub->mini[PLAYER]->instances[0].x = cub->player.current.x;
	cub->mini[PLAYER]->instances[0].y = cub->player.current.y;
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub		*cub;
	double		angle;
	t_dpoint	cur;
	t_dpoint	dir;
	t_dpoint	dir_left;
	t_dpoint	dir_right;

	cub = (t_cub *)param;
	cur = cub->player.current;
	cub->player.next = (t_dpoint){cur.x, cur.y};
	dir = (t_dpoint){(cos(cub->player.angle)), (sin(cub->player.angle))};
	dir_left = (t_dpoint){(cos(cub->player.angle + PI / 2)), (sin(cub->player.angle + PI / 2))};
	dir_right = (t_dpoint){(cos(cub->player.angle + 3 * PI / 2)), (sin(cub->player.angle + 3 * PI / 2))};
	printf("cos = %f, sin =%f\n",(cos(cub->player.angle)), (sin(cub->player.angle)));
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_cub(cub, EXIT_SUCCESS);
	else if (keydata.key == MLX_KEY_W)
		cub->player.next = (t_dpoint){cur.x + dir.x, cur.y - dir.y};
	else if (keydata.key == MLX_KEY_S)
		cub->player.next = (t_dpoint){cur.x - dir.x, cur.y + dir.y};
	else if (keydata.key == MLX_KEY_A)
		cub->player.next = (t_dpoint){cur.x + dir_left.x, cur.y - dir_left.y};
	else if (keydata.key == MLX_KEY_D)
		cub->player.next = (t_dpoint){cur.x + dir_right.x, cur.y - dir_right.y};
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
	// mlx_key_hook(cub->mlx, key_hook, cub);
	ray_casting(cub);
}

static void	close_hook(void *param)
{
	exit_cub((t_cub *)param, EXIT_SUCCESS);
}

void	init_hooks(t_cub *cub)
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

	// cub->rays = (t_ray *)ft_calloc(WIDTH, sizeof(t_ray));
	cub->rays = (t_ray *)ft_calloc(19, sizeof(t_ray)); //5 degree * 18 = 90
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
