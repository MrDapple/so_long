/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:30:19 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/09 14:42:58 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_movement(int keycode, t_vars *mlx)
{
	static int	steps;
	int			c;

	c = steps;
	if (keycode == 53)
		exit(3);
	if (keycode == 126)
		steps += mv_up(mlx);
	if (keycode == 125)
		steps += mv_down(mlx);
	if (keycode == 123)
		steps += mv_left(mlx);
	if (keycode == 124)
		steps += mv_right(mlx);
	if (steps > c)
		ft_printf("Steps:%d [%d/%d]\n", steps, mlx->found, mlx->collect);
	if (mlx->found >= mlx->collect)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_open,
			(mlx->pos_x_e) * X_WIDTH, (mlx->pos_y_e) * X_HEIGHT);
	return (0);
}

int	mv_up(t_vars *mlx)
{
	if (mlx->map[mlx->pos_y - 1][mlx->pos_x] != '1')
	{
		if (mlx->map[mlx->pos_y - 1][mlx->pos_x] == 'E')
		{
			if (mlx->found >= mlx->collect)
				exit (3);
			else
				return (0);
		}
		if (mlx->map[mlx->pos_y - 1][mlx->pos_x] == 'C')
		{
			mlx->map[mlx->pos_y - 1][mlx->pos_x] = '0';
			mlx->found++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, TRAIL,
			(mlx->pos_x) * X_WIDTH, (mlx->pos_y--) * X_HEIGHT);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_up,
			(mlx->pos_x) * X_WIDTH, (mlx->pos_y) * X_HEIGHT);
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
				exit (3);
			else
				return (0);
		}
		if (mlx->map[mlx->pos_y + 1][mlx->pos_x] == 'C')
		{
			mlx->map[mlx->pos_y + 1][mlx->pos_x] = '0';
			mlx->found++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, TRAIL,
			(mlx->pos_x) * X_WIDTH, (mlx->pos_y++) * X_HEIGHT);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_down,
			(mlx->pos_x) * X_WIDTH, (mlx->pos_y) * X_HEIGHT);
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
				exit (3);
			else
				return (0);
		}
		if (mlx->map[mlx->pos_y][mlx->pos_x - 1] == 'C')
		{
			mlx->map[mlx->pos_y][mlx->pos_x - 1] = '0';
			mlx->found++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, TRAIL,
			(mlx->pos_x--) * X_WIDTH, (mlx->pos_y) * X_HEIGHT);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_left,
			(mlx->pos_x) * X_WIDTH, (mlx->pos_y) * X_HEIGHT);
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
				exit (3);
			else
				return (0);
		}
		if (mlx->map[mlx->pos_y][mlx->pos_x + 1] == 'C')
		{
			mlx->map[mlx->pos_y][mlx->pos_x + 1] = '0';
			mlx->found++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, TRAIL,
			(mlx->pos_x++) * X_WIDTH, (mlx->pos_y) * X_HEIGHT);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_right,
			(mlx->pos_x) * X_WIDTH, (mlx->pos_y) * X_HEIGHT);
		return (1);
	}
	return (0);
}
