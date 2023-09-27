/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_gentab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:26:14 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/27 12:47:02 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	**sl_gentab(char *map)
{
	char	**tab;
	char	buff[2] = "";
	char	*res;
	int		fd;
	int		total;

	total = 0;
	fd = open(map , O_RDONLY);
	while (read(fd, &buff, 1))
		total++;
	close(fd);
	res = malloc(sizeof(char) * (total + 1));
	// if (!res)
	res[total] = '\0';
	fd = open(map , O_RDONLY);
	read(fd, res, total);
	tab = ft_split(res, '\n');
	free(res);
	close(fd);
	return (tab);
}
