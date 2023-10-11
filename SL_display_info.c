/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_display_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:12:55 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/10 15:11:24 by anvoets          ###   ########.fr       */
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
		return (sl_free_stop(mlx, 3));
	str_coll = sl_strgen_collect(mlx->found, mlx->collect);
	if (!str_coll)
		return (sl_free_stop(mlx, 3));
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
	int		i;

	i = steps;
	ret = " STEPS:   [";
	if (!ret)
		return (0);
	temp = ft_itoa(steps);
	if (!temp)
		return (sl_strgen_free(temp, ret));
	ret = ft_strjoin(ret, temp);
	if (!ret)
		return (sl_strgen_free(temp, ret));
	ret = ft_strjoin(ret, "]");
	if (!ret)
		return (sl_strgen_free(temp, ret));
	free(temp);
	return (ret);
}

char	*sl_strgen_collect(int found, int collect)
{
	char	*ret;
	char	*temp;

	ret = " COLLECT: [";
	if (!ret)
		return (0);
	temp = ft_itoa(found);
	if (!temp)
		return (sl_strgen_free(temp, ret));
	ret = ft_strjoin(ret, temp);
	if (!ret)
		return (sl_strgen_free(temp, ret));
	ret = sl_collect_gen(ret, collect);
	if (!ret)
		return (sl_strgen_free(temp, ret));
	free(temp);
	return (ret);
}

char	*sl_collect_gen(char *ret, int collect)
{
	char	*temp;

	temp = ft_itoa(collect);
	if (!temp)
		return (sl_strgen_free(temp, ret));
	ret = ft_strjoin(ret, "/");
	if (!ret)
		return (sl_strgen_free(temp, ret));
	ret = ft_strjoin(ret, temp);
	if (!ret)
		return (sl_strgen_free(temp, ret));
	ret = ft_strjoin(ret, "]");
	if (!ret)
		return (sl_strgen_free(temp, ret));
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
