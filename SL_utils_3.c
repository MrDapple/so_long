/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:18:43 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/16 12:36:17 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_input(char *in, char *com)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (in[c])
	{
		while (in[c] == com[++i])
		{
			if (!in[c])
				return (1);
			c++;
		}
		i = 0;
		if (in[c])
			c++;
	}
	return (0);
}

int	sl_free_stop(t_vars *mlx, int errorcode)
{
	int	i;

	i = 0;
	if (errorcode == 10)
	{
		sl_destroy_img(mlx);
		sl_free_tab(mlx->map);
		sl_free_tab(mlx->t_map);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (errorcode == 5)
		sl_destroy_img(mlx);
	if (errorcode >= 1)
		ft_printf("error\n");
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	sl_end_x(t_vars *mlx)
{
	sl_destroy_img(mlx);
	sl_free_tab(mlx->map);
	sl_free_tab(mlx->t_map);
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
