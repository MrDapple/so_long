/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_display_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:12:55 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/13 17:36:59 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_display_info(t_vars *mlx, int steps)
{
	char	*str_step;
	char	*str_coll;
	void	*back;

	str_step = sl_strgen_steps(steps);
	if (!str_step)
		return (sl_free_stop(mlx, 5));
	str_coll = sl_strgen_collect(mlx->found, mlx->collect);
	if (!str_coll)
		return (sl_free_stop(mlx, 5));
	back = sl_img_back(mlx);
	if (!back)
		return (sl_display_freestop(mlx, str_step, str_coll, back));
	mlx_put_image_to_window(mlx->mlx, mlx->win, back, 0, 0);
	mlx_destroy_image(mlx->mlx, back);
	mlx_string_put(mlx->mlx, mlx->win, 0, 15, 0x003399FF, str_step);
	free(str_step);
	if (mlx->found >= mlx->collect)
		sl_display_succes(mlx->mlx, mlx->win, str_coll);
	else
		mlx_string_put(mlx->mlx, mlx->win, 0, 35, 0x00FFFF33, str_coll);
	free(str_coll);
	return (1);
}

char	*sl_strgen_steps(int steps)
{
	char	*ret;
	char	*temp;
	char	*nr;

	temp = " STEPS:   [";
	nr = ft_itoa(steps);
	if (!nr)
		return (0);
	ret = ft_strjoin(temp, nr);
	if (!ret)
		return (sl_strgen_free(temp, ret));
	free(nr);
	temp = ret;
	ret = ft_strjoin(temp, "]");
	if (!ret)
		return (sl_strgen_free(temp, ret));
	free(temp);
	return (ret);
}

char	*sl_strgen_collect(int found, int collect)
{
	char	*ret;
	char	*temp;
	char	*huh;
	char	*nr;

	temp = " COLLECT: [";
	huh = sl_collect_gen(collect);
	if (!huh)
		return (0);
	nr = ft_itoa(found);
	if (!nr)
		return (0);
	ret = ft_strjoin(temp, nr);
	if (!ret)
		return (sl_strgen_free(temp, ret));
	free(nr);
	temp = ret;
	ret = ft_strjoin(temp, huh);
	if (!ret)
		return (sl_strgen_free(temp, ret));
	free(huh);
	free(temp);
	return (ret);
}

char	*sl_collect_gen(int collect)
{
	char	*ret;
	char	*temp;
	char	*nr;

	ret = "/";
	nr = ft_itoa(collect);
	if (!nr)
		return (0);
	temp = ret;
	ret = ft_strjoin(temp, nr);
	if (!ret)
		return (0);
	free(nr);
	temp = ret;
	ret = ft_strjoin(temp, "]");
	if (!ret)
		return (0);
	free(temp);
	return (ret);
}

char	*sl_strgen_free(char *temp, char *ret)
{
	if (temp)
		free(temp);
	if (ret)
		free(ret);
	return (0);
}
