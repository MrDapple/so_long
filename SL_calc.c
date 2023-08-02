/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:32:16 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/02 14:13:59 by anvoets          ###   ########.fr       */
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
			if (t == 'w')
				return (c1);
			if (t == 'h')
				return (c2);
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

int	sl_line_len(char *line, char c, char f)
{
	int	cnt;

	cnt = 0;
	while (line[cnt] && line[cnt] != c)
	{
		if (line[cnt] != f)
			return (0);
		cnt++;
	}
	return (cnt);
}

int	sl_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}