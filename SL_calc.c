/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:32:16 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/02 12:31:38 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_win_calc(t_vars *mlx, char t)
{
	int	c;

	c = 0;
	if (t == 'w')
	{
		while (mlx->map[0][c])
			c++;
		return (c);
	}
	if (t == 'h')
	{
		while (mlx->map[c])
			c++;
		return (c);
	}
	return (0);
}

int	sl_pos_calc(t_vars *mlx, char t, char find)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (c1 <= mlx->win_h)
	{
		if (mlx->map[c1][c2] == find && mlx->map[c1][c2] != '\0')
		{
			if (t == 'x')
				return (c2);
			if (t == 'y')
				return (c1);
		}
		if (c2 == mlx->win_w)
		{
			c1++;
			c2 = 0;
		}
		else
			c2++;
	}
	return (0);
}

int	sl_collect_calc(t_vars *mlx, char find)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	mlx->collect = 0;
	while (c1 <= mlx->win_h && mlx->map[c1])
	{
		if (mlx->map[c1][c2] == find && mlx->map[c1][c2] != '\0')
		{
			mlx->collect++;
		}
		if (c2 == mlx->win_w)
		{
			c1++;
			c2 = 0;
		}
		else
			c2++;
	}
	return (0);
}

int	sl_find_calc(t_vars *mlx, char find)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (c1 <= mlx->win_h && mlx->map[c1])
	{
		c2 = 0;
		while (c2 <= mlx->win_w)
		{
			if (mlx->map[c1][c2] == find && find == 'P')
				mlx->player++;
			if (mlx->map[c1][c2] == find && find == 'E')
				mlx->exit++;
			c2++;
		}
		c1++;
	}
	return (0);
}
