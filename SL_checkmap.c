/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/21 16:37:16 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// RECURSION
int	sl_iswalk(char c, char *lst)
{
	int		i;

	i = 0;
	while (lst[i])
	{
		if (lst[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	sl_calcopt(char **map, int y, int x)
{
	if (sl_iswalk(map[y - 1][x], "E0C") == 1)
		return (1);
	else if (sl_iswalk(map[y][x - 1], "E0C") == 1)
		return (2);
	else if (sl_iswalk(map[y + 1][x], "E0C") == 1)
		return (3);
	else if (sl_iswalk(map[y][x + 1], "E0C") == 1)
		return (4);
	// ft_printf("retrnopt = [%d]\n", cnt);
	return (0);
}

int	sl_reset_tab(char **map)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	while (map[h])
	{
		if (map[h][w] == '4')
			map[h][w] = 'E';
		if (map[h][w] == '3')
			map[h][w] = 'C';
		if (map[h][w] == '2')
			map[h][w] = '0';
		if (map[h][w] == '\0')
		{
			w = 0;
			h++;
		}
		else
			w++;
	}
	return (0);
}

int	sl_check(char **map, int y, int x, char c)
{
	if (map[y][x] == 'E' && c == 'E')
		return (1);
	else if (map[y][x] == 'C' && c == 'C')
		return (1);
	return (0);
}

char	sl_swap(char **map, int y, int x)
{
	if (map[y][x] == 'E')
		return ('4');
	else if (map[y][x] == 'C')
		return ('3');
	else if (map[y][x] == '0')
		return ('2');
	// else if (map[y][x] == '2')
	// 	return ();
	return ('2');
}

int	sl_is_possible(char **map, int y, int x, int collect)
{
	int	c;
	int	e;
	int			dir;
	int			paths;

	paths = 0;
	c = 0;
	e = 0;
	dir = 5;
	av_print_tab(map);
	ft_printf("'%c'[%d][%d]\n", map[y][x], y, x);
	while (c != collect || e != 3)
	{
		c += sl_check(map, y, x, 'C');
		e += sl_check(map, y, x, 'E');
		while (sl_iswalk(map[y - 1][x], "E0C") == 1 && (c != collect || e != 3))
		{
			paths++;
			c += sl_check(map, y, x, 'C');
			e += sl_check(map, y, x, 'E');
			ft_printf("U[%d/%d][%d], ", c, collect, e);
			map[y][x] = sl_swap(map, y, x);
			y--;
		}
		c += sl_check(map, y, x, 'C');
		e += sl_check(map, y, x, 'E');
		while (sl_iswalk(map[y][x - 1], "E0C") == 1 && (c != collect || e != 3))
		{
			paths++;
			c += sl_check(map, y, x, 'C');
			e += sl_check(map, y, x, 'E');
			ft_printf("L[%d/%d][%d], ", c, collect, e);
			map[y][x] = sl_swap(map, y, x);
			x--;
		}
		c += sl_check(map, y, x, 'C');
		e += sl_check(map, y, x, 'E');
		while (sl_iswalk(map[y + 1][x], "E0C") == 1 && (c != collect || e != 3))
		{
			paths++;
			c += sl_check(map, y, x, 'C');
			e += sl_check(map, y, x, 'E');
			ft_printf("D[%d/%d][%d], ", c, collect, e);
			map[y][x] = sl_swap(map, y, x);
			y++;
		}
		c += sl_check(map, y, x, 'C');
		e += sl_check(map, y, x, 'E');
		while (sl_iswalk(map[y][x + 1], "E0C") == 1 && (c != collect || e != 3))
		{
			paths++;
			c += sl_check(map, y, x, 'C');
			e += sl_check(map, y, x, 'E');
			ft_printf("R[%d/%d][%d], ", c, collect, e);
			map[y][x] = sl_swap(map, y, x);
			x++;
		}
		c += sl_check(map, y, x, 'C');
		e += sl_check(map, y, x, 'E');
		map[y][x] = sl_swap(map, y, x);
		while (sl_calcopt(map, y, x) == 0 && (c != collect || e != 3))
		{
			while (sl_iswalk(map[y][x - 1], "234") == 1 && sl_calcopt(map, y, x) == 0)
			{
				paths++;
				ft_printf("2L[%d/%d][%d], ", c, collect, e);
				x--;
			}
			while (sl_iswalk(map[y - 1][x], "234") == 1 && sl_calcopt(map, y, x) == 0)
			{
				paths++;
				ft_printf("2U[%d/%d][%d], ", c, collect, e);
				y--;
			}
			while (sl_iswalk(map[y][x + 1], "234") == 1 && sl_calcopt(map, y, x) == 0)
			{
				paths++;
				ft_printf("2R[%d/%d][%d], ", c, collect, e);
				x++;
			}
			while (sl_iswalk(map[y + 1][x], "234") == 1 && sl_calcopt(map, y, x) == 0)
			{
				paths++;
				ft_printf("2D[%d/%d][%d], ", c, collect, e);
				y++;
			}
		}
		paths++;
		dir = sl_calcopt(map, y, x);
	}
	ft_printf("\nEND\n");
	av_print_tab(map);
	sl_reset_tab(map);
	av_print_tab(map);
	return (1);
}
