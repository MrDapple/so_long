/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/09 15:01:01 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// RECURSION 

int	sl_is_possible(t_vars *mlx)
{
	int	pos_x;
	int	pos_y;

	pos_x = mlx->pos_x;
	pos_y = mlx->pos_y;
	ft_printf("'%c'[%d][%d]\n", mlx->map[mlx->pos_y][mlx->pos_x], mlx->pos_y, mlx->pos_x);
	// while ()
	return (1);
}