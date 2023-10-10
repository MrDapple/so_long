/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_gentab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:26:14 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/10 12:40:36 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_checkmap(char **map)
{
	int	c1;
	int	c2;
	int	x;

	c1 = 0;
	c2 = -1;
	x = ft_strlen(map[c1]);
	if (sl_check_tb(map, x) == 0)
		return (0);
	c2 = 0;
	while (map[++c1 + 1])
	{
		if (map[c1][c2] != '1')
			return (0);
		while (map[c1][c2])
		{
			if (sl_check_val(map[c1][c2], "10CEP") == 0)
				return (0);
			c2++;
		}
		if (c2 != x || map[c1][x - 1] != '1')
			return (0);
		c2 = 0;
	}
	return (1);
}

int	sl_check_val(char check, char *lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		if (lst[i] == check && lst)
			return (1);
		i++;
	}
	return (0);
}

char	**sl_gentab(char *map)
{
	char	**tab;
	char	buff[2];
	char	*res;
	int		fd;
	int		total;

	total = 0;
	fd = open(map, O_RDONLY);
	while (fd != -1 && read(fd, &buff, 1))
		total++;
	close(fd);
	res = malloc(sizeof(char) * (total + 1));
	if (sl_rip(res, total, fd) == 0)
		return (0);
	res[total] = '\0';
	fd = open(map, O_RDONLY);
	if (fd < 0 || read(fd, res, total) < 0)
		return (0);
	tab = ft_split(res, '\n');
	free(res);
	close(fd);
	if (tab && sl_checkmap(tab) == 1)
		return (tab);
	free(tab);
	return (0);
}

int	sl_rip(char *res, int total, int fd)
{
	if (!res || total <= 0)
	{
		free(res);
		close(fd);
		return (0);
	}
	return (1);
}

int	sl_check_tb(char **map, int x)
{
	int	c1;
	int	c2;
	int	c3;

	c1 = 0;
	c2 = 0;
	c3 = 0;
	if (x <= 0)
		return (0);
	while (map[c1][c2] == '1')
		c2++;
	if (c2 != x)
		return (0);
	c2 = 0;
	while (map[c1])
	{
		c1++;
	}
	while (map[c1 - 1][c2] == '1')
		c2++;
	if (c2 != x)
		return (0);
	return (1);
}
