/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/27 12:47:56 by anvoets          ###   ########.fr       */
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
	{
		mlx->exit_check = 1;
		return (1);
	}
	map[y][x] = '1';
	sl_is_possible(map, y - 1, x, mlx);
	sl_is_possible(map, y, x - 1, mlx);
	sl_is_possible(map, y + 1, x, mlx);
	sl_is_possible(map, y, x + 1, mlx);
	return (1);
}

int	sl_free_stop(t_vars *mlx, int errorcode)
{
	int	i;

	i = 0;
	if (mlx)
	// {
	// // sl_destroy_img(mlx);
	// if (mlx->map)
	// {
	// 	while (mlx->map[i])
	// 		free(mlx->map[i++]);
	// 	free(mlx->map);
	// }
	i = 0;
	// if (mlx->t_map)
	// {
	// 	while (mlx->t_map[i])
	// 		free(mlx->map[i++]);
	// 	free(mlx->t_map);
	// }
	// if (mlx->win)
	// 	mlx_destroy_window(mlx->mlx, mlx->win);
	// }
	if (errorcode == 1)
		ft_printf("error STOP\n");
	exit(3);
	return (0);
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
	return (1);
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
	mlx->pos_x = sl_pos_calc(mlx, 'x', 'P');
	mlx->pos_y = sl_pos_calc(mlx, 'y', 'P');
	mlx->pos_x_e = sl_pos_calc(mlx, 'x', 'E');
	mlx->pos_y_e = sl_pos_calc(mlx, 'y', 'E');
	return (1);
}