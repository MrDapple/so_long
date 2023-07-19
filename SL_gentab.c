/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_gentab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:26:14 by anvoets           #+#    #+#             */
/*   Updated: 2023/07/19 17:41:01 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	sl_checkmap(int fd, int w, int h)
{
	int		cnt;
	char	*line;
	int		comp;

	w = 0;
	h = 1;
	comp = 0;
	cnt = 0;
	line = get_next_line(fd);
	w = sl_line_len(line, '\n', '1');
	h++;
	line = get_next_line(fd);
	while (av_check_nl(line) == YES && (line[0] == '1' && line[w - 1] == '1'))
	{
		line = get_next_line(fd);
		comp = sl_line_len(line, '\n', '1');
		h++;
	}
	if (comp != w)
		return (0);
	return (h);
}

char	**sl_generate(int fd, int w, int h)
{
	char	**tab;
	char	*res;
	int		c1;

	c1 = 0;
	tab = malloc(sizeof(char **) * (h + 1));
	if (!tab)
		return (0);
	while (c1 <= h)
	{
		// tab[c1] = malloc(sizeof(char *) * (w + 1));
		// if (!tab[c1])
		// {
		// 	while (c1 >= 0)
		// 	{
		// 		free(tab[c1]);
		// 		c1--;
		// 	}
		// 	free(tab);
		// 	return (0);
		// }
		res = get_next_line(fd);
		tab[c1] = res;
		// tab[c1][w-1] = '\0';
		ft_printf("[%s]", res);
		c1++;
	}
	return (tab);
}

char	**sl_gentab(char *map)
{
	char	**tab;
	char	buff[2] = "";
	char	*res;
	int		fd;
	int		total;

	total = 0;
	// res = NULL;
	fd = open(map, O_RDONLY);
	while (read(fd, &buff, 1))
	{
		total++;
	}
	close (fd);
	res = malloc(sizeof(char) * (total+1));
	res[total] = '\0';
	fd = open(map, O_RDONLY);
	read(fd, res, total);
	tab = ft_split(res, '\n');
	free (res);
	close (fd);
	return (tab);
}

// char	*sl_clean_line(char	*str)
// {
// 	int	cnt;
// 	int	*res;
	
// 	while (str[cnt] && str[cnt])
// }
int	sl_win_calc(t_vars mlx, char t)
{
	int c;

	c = 0;
	if (t == 'w')
	{
		while (mlx.map[0][c])
			c++;
		return (c);
	}
	if (t == 'h')
	{
		while (mlx.map[c])
			c++;
		return (c);
	}
	return (0);
}

int	sl_pos_calc(t_vars mlx, char t, char find)
{
	int c1;
	int c2;
	int	win_w = 0;
	int	win_h = 0;

	win_w = sl_win_calc(mlx, 'w');
	win_h = sl_win_calc(mlx, 'h');
	c1 = 0;
	c2 = 0;
	while (c1 <= mlx.win_h)
	{
		if (mlx.map[c1][c2] == find)
		{
			if (t == 'w')
			 	return (c2);
			if (t == 'h')
			 	return (c1);
		}
		if (c2 == mlx.win_w)
		{
			c2 = 0;
			c1++;
		}
		else
			c2++;
	}
	return (0);
}

int	sl_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

// char	**sl_splitclean(char **tab)
// {
// 	int	c1;
// 	int	total;
// 	char	**res;

// 	c1 = 0;
// 	c2 = 0;
// 	total = 0;
// 	while (tab[c1])
// 	{
// 	}
// 	free (tab);
// 	return (res);
// }

