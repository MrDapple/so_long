/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/23 15:45:42 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_is_possible(char **map, int y, int x, t_vars *mlx)
{
	if (!mlx->coll_check)
		mlx->coll_check = 0;
	if (!mlx->exit_check)
		mlx->exit_check = 0;
	if (mlx->exit_check == 1 && mlx->coll_check >= mlx->collect)
		return (1);
	if (map[y][x] == '1')
		return (1);
	else if (map[y][x] == 'C')
		mlx->coll_check++;
	else if (map[y][x] == 'E')
	{
		mlx->exit_check = 1;
		return (1);
	}
	map[y][x] = '1';
	sl_is_possible(map, y - 1, x, mlx);
	sl_is_possible(map, y, x - 1, mlx);
	sl_is_possible(map, y + 1, x, mlx);
	sl_is_possible(map, y, x + 1, mlx);
	return (1);
}
