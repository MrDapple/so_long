/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:30:19 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/09 12:20:40 by anvoets          ###   ########.fr       */
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
			(mlx->pos_w_e) * 100, (mlx->pos_h_e) * 100);
	return (0);
}

int	mv_up(t_vars *mlx)
{
	if (mlx->map[mlx->pos_h - 1][mlx->pos_w] != '1')
	{
		if (mlx->map[mlx->pos_h - 1][mlx->pos_w] == 'E')
		{
			if (mlx->found >= mlx->collect)
				exit (3);
			else
				return (0);
		}
		if (mlx->map[mlx->pos_h - 1][mlx->pos_w] == 'C')
		{
			mlx->map[mlx->pos_h - 1][mlx->pos_w] = '0';
			mlx->found++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, TRAIL,
			(mlx->pos_w) * 100, (mlx->pos_h--) * 100);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_up,
			(mlx->pos_w) * 100, (mlx->pos_h) * 100);
		return (1);
	}
	return (0);
}

int	mv_down(t_vars *mlx)
{
	if (mlx->map[mlx->pos_h + 1][mlx->pos_w] != '1')
	{
		if (mlx->map[mlx->pos_h + 1][mlx->pos_w] == 'E')
		{
			if (mlx->found >= mlx->collect)
				exit (3);
			else
				return (0);
		}
		if (mlx->map[mlx->pos_h + 1][mlx->pos_w] == 'C')
		{
			mlx->map[mlx->pos_h + 1][mlx->pos_w] = '0';
			mlx->found++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, TRAIL,
			(mlx->pos_w) * 100, (mlx->pos_h++) * 100);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_down,
			(mlx->pos_w) * 100, (mlx->pos_h) * 100);
		return (1);
	}
	return (0);
}

int	mv_left(t_vars *mlx)
{
	if (mlx->map[mlx->pos_h][mlx->pos_w - 1] != '1')
	{
		if (mlx->map[mlx->pos_h][mlx->pos_w - 1] == 'E')
		{
			if (mlx->found >= mlx->collect)
				exit (3);
			else
				return (0);
		}
		if (mlx->map[mlx->pos_h][mlx->pos_w - 1] == 'C')
		{
			mlx->map[mlx->pos_h][mlx->pos_w - 1] = '0';
			mlx->found++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, TRAIL,
			(mlx->pos_w--) * 100, (mlx->pos_h) * 100);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_left,
			(mlx->pos_w) * 100, (mlx->pos_h) * 100);
		return (1);
	}
	return (0);
}

int	mv_right(t_vars *mlx)
{
	if (mlx->map[mlx->pos_h][mlx->pos_w + 1] != '1')
	{
		if (mlx->map[mlx->pos_h][mlx->pos_w + 1] == 'E')
		{
			if (mlx->found >= mlx->collect)
				exit (3);
			else
				return (0);
		}
		if (mlx->map[mlx->pos_h][mlx->pos_w + 1] == 'C')
		{
			mlx->map[mlx->pos_h][mlx->pos_w + 1] = '0';
			mlx->found++;
		}
		mlx_put_image_to_window(mlx->mlx, mlx->win, TRAIL,
			(mlx->pos_w++) * 100, (mlx->pos_h) * 100);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_right,
			(mlx->pos_w) * 100, (mlx->pos_h) * 100);
		return (1);
	}
	return (0);
}
