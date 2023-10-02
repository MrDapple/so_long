/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:13 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/02 16:02:01 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_free_stop(t_vars *mlx, int errorcode)
{
	int	i;

	i = 0;
	if (errorcode >= 3)
	{
		sl_destroy_img(mlx);
	}
	if (errorcode >= 2)
	{
		free(mlx->map);
		free(mlx->t_map);
	}
	if (errorcode >= 1)
		ft_printf("error\n");
	exit(3);
	return (0);
}

char	*sl_index(char type, t_vars *mlx)
{
	if (type == '1')
		return (mlx->tex_wall);
	if (type == '0')
		return (mlx->tex_floor);
	if (type == 'P')
		return (mlx->tex_p_up);
	if (type == 'C')
		return (mlx->tex_collectible);
	if (type == 'E')
		return (mlx->tex_closed);
	return (0);
}

int	sl_map_render(t_vars *mlx)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
	while (mlx->map[h])
	{
		if (mlx->map[h][w] != '\0')
			mlx_put_image_to_window(mlx->mlx, mlx->win, sl_index(mlx->map[h][w],
					mlx), w * X_W, h * X_H);
		if (mlx->map[h][w] == '\0')
		{
			w = 0;
			h++;
		}
		else
			w++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	mlx;
	int		win_w;
	int		win_h;

	win_w = 0;
	win_h = 0;
	if (argc != 2 || !argv[1])
		return (ft_printf("error\n"));
	sl_set_vars(&mlx, argv[1]);
	sl_is_possible(mlx.t_map, mlx.pos_y, mlx.pos_x, &mlx);
	if (mlx.collect < 1 || mlx.player != 1 || mlx.exit != 1
		|| mlx.exit_check != 1 || mlx.coll_check < mlx.collect)
		return (sl_free_stop(&mlx, 2));
	mlx.mlx = mlx_init();
	if (sl_settex(&mlx) == 0)
		return (sl_free_stop(&mlx, 3));
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_w * X_W, mlx.win_h * X_H,
			"so_long");
	sl_map_render(&mlx);
	mlx.map[mlx.pos_y][mlx.pos_x] = '0';
	mlx_key_hook(mlx.win, sl_movement, &mlx);
	mlx_loop(mlx.mlx);
	sl_free_stop(&mlx, 0);
	return (0);
}
