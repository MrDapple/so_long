/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:30:19 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/13 17:14:50 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_movement(int keycode, t_vars *mlx)
{
	static int	steps;
	int			c;

	c = steps;
	if (keycode == 53)
		sl_free_stop(mlx, 10);
	else if (keycode == 126)
		steps += mv_up(mlx);
	else if (keycode == 125)
		steps += mv_down(mlx);
	else if (keycode == 123)
		steps += mv_left(mlx);
	else if (keycode == 124)
		steps += mv_right(mlx);
	if (mlx->found >= mlx->collect)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_open,
			(mlx->pos_x_e) * X_W, (mlx->pos_y_e) * X_H);
	if (steps > c)
	{
		if (sl_display_info(mlx, steps) != 1)
			sl_free_stop(mlx, 5);
	}
	return (0);
}

int	mv_up(t_vars *mlx)
{
	if (mlx->map[mlx->pos_y - 1][mlx->pos_x] != '1')
	{
		if (mlx->map[mlx->pos_y - 1][mlx->pos_x] == 'E')
		{
			if (mlx->found >= mlx->collect)
				sl_free_stop(mlx, 10);
			mlx->map[mlx->pos_y - 1][mlx->pos_x] = 'E';
		}
		if (mlx->map[mlx->pos_y - 1][mlx->pos_x] == 'C')
		{
			mlx->map[mlx->pos_y - 1][mlx->pos_x] = '0';
			mlx->found++;
		}
		if (mlx->map[mlx->pos_y][mlx->pos_x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_closed,
				(mlx->pos_x) * X_W, (mlx->pos_y--) * X_H);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_trail,
				(mlx->pos_x) * X_W, (mlx->pos_y--) * X_H);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_up,
			(mlx->pos_x) * X_W, (mlx->pos_y) * X_H);
		return (1);
	}
	return (0);
}

int	mv_down(t_vars *mlx)
{
	if (mlx->map[mlx->pos_y + 1][mlx->pos_x] != '1')
	{
		if (mlx->map[mlx->pos_y + 1][mlx->pos_x] == 'E')
		{
			if (mlx->found >= mlx->collect)
				sl_free_stop(mlx, 10);
			mlx->map[mlx->pos_y + 1][mlx->pos_x] = 'E';
		}
		if (mlx->map[mlx->pos_y + 1][mlx->pos_x] == 'C')
		{
			mlx->map[mlx->pos_y + 1][mlx->pos_x] = '0';
			mlx->found++;
		}
		if (mlx->map[mlx->pos_y][mlx->pos_x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_closed,
				(mlx->pos_x) * X_W, (mlx->pos_y++) * X_H);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_trail,
				(mlx->pos_x) * X_W, (mlx->pos_y++) * X_H);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_down,
			(mlx->pos_x) * X_W, (mlx->pos_y) * X_H);
		return (1);
	}
	return (0);
}

int	mv_left(t_vars *mlx)
{
	if (mlx->map[mlx->pos_y][mlx->pos_x - 1] != '1')
	{
		if (mlx->map[mlx->pos_y][mlx->pos_x - 1] == 'E')
		{
			if (mlx->found >= mlx->collect)
				sl_free_stop(mlx, 10);
			mlx->map[mlx->pos_y][mlx->pos_x - 1] = 'E';
		}
		if (mlx->map[mlx->pos_y][mlx->pos_x - 1] == 'C')
		{
			mlx->map[mlx->pos_y][mlx->pos_x - 1] = '0';
			mlx->found++;
		}
		if (mlx->map[mlx->pos_y][mlx->pos_x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_closed,
				(mlx->pos_x--) * X_W, (mlx->pos_y) * X_H);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_trail,
				(mlx->pos_x--) * X_W, (mlx->pos_y) * X_H);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_left,
			(mlx->pos_x) * X_W, (mlx->pos_y) * X_H);
		return (1);
	}
	return (0);
}

int	mv_right(t_vars *mlx)
{
	if (mlx->map[mlx->pos_y][mlx->pos_x + 1] != '1')
	{
		if (mlx->map[mlx->pos_y][mlx->pos_x + 1] == 'E')
		{
			if (mlx->found >= mlx->collect)
				sl_free_stop(mlx, 10);
			mlx->map[mlx->pos_y][mlx->pos_x + 1] = 'E';
		}
		if (mlx->map[mlx->pos_y][mlx->pos_x + 1] == 'C')
		{
			mlx->map[mlx->pos_y][mlx->pos_x + 1] = '0';
			mlx->found++;
		}
		if (mlx->map[mlx->pos_y][mlx->pos_x] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_closed,
				(mlx->pos_x++) * X_W, (mlx->pos_y) * X_H);
		else
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_trail,
				(mlx->pos_x++) * X_W, (mlx->pos_y) * X_H);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_right,
			(mlx->pos_x) * X_W, (mlx->pos_y) * X_H);
		return (1);
	}
	return (0);
}
