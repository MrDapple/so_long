/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_display_info_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:44:34 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/10 12:49:01 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*sl_img_back(t_vars *mlx)
{
	void	*back;
	int		x;

	back = mlx_xpm_file_to_image(mlx->mlx, "images/backscore.xpm", &x, &x);
	return (back);
}

int	sl_display_freestop(t_vars *mlx, char *str1, char *str2, void *back)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (back)
		mlx_destroy_image(mlx->mlx, back);
	return (0);
}

void	sl_display_succes(void *mlx, void *win, char *str)
{
	mlx_string_put(mlx, win, 0, 55, 0x0000FF00, " THE DOOR IS OPEN!");
	mlx_string_put(mlx, win, 0, 35, 0x0000FF00, str);
}
