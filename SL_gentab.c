/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_gentab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:26:14 by anvoets           #+#    #+#             */
/*   Updated: 2023/07/18 12:55:08 by anvoets          ###   ########.fr       */
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

	w = 0;
	h = 1;
	cnt = 0;
	line = get_next_line(fd);
	w = sl_line_len(line, '\n', '1');
	h++;
	line = get_next_line(fd);
	while (av_check_nl(line) == YES && (line[0] == '1' && line[w - 1] == '1'))
	{
		line = get_next_line(fd);
		h++;
	}
	if (sl_line_len(line, '\n', '1') != w)
		return (0);
	return (h);
}

char	**sl_generate(int fd, int w, int h)
{
	char	**tab;
	int		c1;

	c1 = 0;
	tab = malloc(sizeof(char **) * (h + 1));
	if (!tab)
		return (0);
	while (c1 <= h)
	{
		tab[c1] = get_next_line(fd);
		c1++;
	}
	return (tab);
}

char	**sl_gentab(char *map)
{
	char	**tab;
	int 	fd;
	static int	h;
	static int	w;

	fd = open(map, O_RDONLY);
	h = sl_checkmap(fd, w, h);
	if (h == 0)
	{
		close(fd);
		return (0);
	}
	close (fd);
	fd = open(map, O_RDONLY);
	tab = sl_generate(fd, w, h);
	close (fd);
	return (tab);
}
