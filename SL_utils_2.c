/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/02 16:01:09 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_is_possible(char **map, int y, int x, t_vars *mlx)
{
	if (!mlx->coll_check)
		mlx->coll_check = 0;
	if (!mlx->exit_check)
		mlx->exit_check = 0;
	if (mlx->exit_check == 1 && mlx->coll_check >= mlx->collect)
		return (1);
	if (map[y][x] == '1')
		return (1);
	else if (map[y][x] == 'C')
		mlx->coll_check++;
	else if (map[y][x] == 'E')
		mlx->exit_check = 1;
	map[y][x] = '1';
	sl_is_possible(map, y - 1, x, mlx);
	sl_is_possible(map, y, x - 1, mlx);
	sl_is_possible(map, y + 1, x, mlx);
	sl_is_possible(map, y, x + 1, mlx);
	return (1);
}

int	sl_settex(t_vars *mlx)
{
	int	x;

	x = 0;
	mlx->tex_p_up = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_up.xpm", &x, &x);
	mlx->tex_p_down = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_down.xpm", &x, &x);
	mlx->tex_p_left = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_left.xpm", &x, &x);
	mlx->tex_p_right = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_right.xpm", &x, &x);
	mlx->tex_wall = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/1.xpm", &x, &x);
	mlx->tex_floor = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/0.xpm", &x, &x);
	mlx->tex_trail = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/0.xpm", &x, &x);
	mlx->tex_collectible = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/C.xpm", &x, &x);
	mlx->tex_closed = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/E.xpm", &x, &x);
	mlx->tex_open = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/E_lc.xpm", &x, &x);
	return (sl_checktex(mlx));
}

int	sl_checktex(t_vars *mlx)
{
	if (!mlx->tex_p_up)
		return (0);
	else if (!mlx->tex_p_down)
		return (0);
	else if (!mlx->tex_p_left)
		return (0);
	else if (!mlx->tex_p_right)
		return (0);
	else if (!mlx->tex_wall)
		return (0);
	else if (!mlx->tex_floor)
		return (0);
	else if (!mlx->tex_trail)
		return (0);
	else if (!mlx->tex_collectible)
		return (0);
	else if (!mlx->tex_closed)
		return (0);
	else if (!mlx->tex_open)
		return (0);
	return (1);
}

int	sl_destroy_img(t_vars *mlx)
{
	if (mlx->tex_p_up)
		mlx_destroy_image(mlx->mlx, mlx->tex_p_up);
	if (mlx->tex_p_down)
		mlx_destroy_image(mlx->mlx, mlx->tex_p_down);
	if (mlx->tex_p_left)
		mlx_destroy_image(mlx->mlx, mlx->tex_p_left);
	if (mlx->tex_p_right)
		mlx_destroy_image(mlx->mlx, mlx->tex_p_right);
	if (mlx->tex_wall)
		mlx_destroy_image(mlx->mlx, mlx->tex_wall);
	if (mlx->tex_floor)
		mlx_destroy_image(mlx->mlx, mlx->tex_floor);
	if (mlx->tex_trail)
		mlx_destroy_image(mlx->mlx, mlx->tex_trail);
	if (mlx->tex_collectible)
		mlx_destroy_image(mlx->mlx, mlx->tex_collectible);
	if (mlx->tex_closed)
		mlx_destroy_image(mlx->mlx, mlx->tex_closed);
	if (mlx->tex_open)
		mlx_destroy_image(mlx->mlx, mlx->tex_open);
	return (0);
}

int	sl_set_vars(t_vars *mlx, char *map)
{
	mlx->map = sl_gentab(map);
	if (!mlx->map)
		return (sl_free_stop(mlx, 1));
	mlx->t_map = sl_gentab(map);
	if (!mlx->t_map)
		return (sl_free_stop(mlx, 1));
	mlx->win_w = sl_win_calc(mlx, 'w');
	mlx->win_h = sl_win_calc(mlx, 'h');
	sl_collect_calc(mlx, 'C');
	mlx->player = 0;
	sl_find_calc(mlx, 'P');
	mlx->exit = 0;
	sl_find_calc(mlx, 'E');
	mlx->pos_x = sl_pos_calc(mlx, 'x', 'P');
	mlx->pos_y = sl_pos_calc(mlx, 'y', 'P');
	mlx->pos_x_e = sl_pos_calc(mlx, 'x', 'E');
	mlx->pos_y_e = sl_pos_calc(mlx, 'y', 'E');
	return (1);
}
