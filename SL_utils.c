/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:13 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/28 09:32:18 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	av_print_tab(char **map)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (map[h])
	{
		ft_printf("[%d]%s\n", h, map[h]);
		h++;
	}
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

int	sl_settex(t_vars *mlx)
{
	int	x;

	x = 0;
	mlx->tex_p_up = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_up.xpm", &x, &x);
	mlx->tex_p_down = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_down.xpm", &x, &x);
	mlx->tex_p_left = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_left.xpm", &x, &x);
	mlx->tex_p_right = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_right.xpm", &x, &x);
	mlx->tex_wall = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/1.xpm", &x, &x);
	mlx->tex_floor = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/0.xpm", &x, &x);
	mlx->tex_trail = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/0.xpm", &x, &x);
	mlx->tex_collectible = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/C.xpm", &x, &x);
	mlx->tex_closed = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/E.xpm", &x, &x);
	mlx->tex_open = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/E_lc.xpm", &x, &x);

	// mlx->tex_p_up = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/blue_up.xpm", &x, &x);
	// mlx->tex_p_down = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/blue_down.xpm", &x, &x);
	// mlx->tex_p_left = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/blue_left.xpm", &x, &x);
	// mlx->tex_p_right = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/blue_right.xpm", &x, &x);
	// mlx->tex_wall = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/grey.xpm", &x, &x);
	// mlx->tex_floor = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/white.xpm", &x, &x);
	// mlx->tex_trail = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/blue.xpm", &x, &x);
	// mlx->tex_collectible = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/yellow.xpm", &x, &x);
	// mlx->tex_closed = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/red.xpm", &x, &x);
	// mlx->tex_open = mlx_xpm_file_to_image(mlx->mlx,
	// 		"images/programmer/green.xpm", &x, &x);
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

int	so_long()
{
	t_vars	mlx;
	int		win_w;
	int		win_h;

	win_w = 0;
	win_h = 0;
	mlx.found = 0;
	mlx.mlx = mlx_init();
	if (sl_set_vars(&mlx) == 0)
		return (ft_printf("error\n"));
	sl_collect_calc(&mlx, 'C');
	sl_is_possible(mlx.t_map, mlx.pos_y, mlx.pos_x, &mlx);
	if (mlx.coll_check != mlx.collect || mlx.exit_check != 1)
		return (ft_printf("error\n"));
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_w * X_W, mlx.win_h * X_H,
			"so_long");
	sl_settex(&mlx);
	sl_map_render(&mlx);
	mlx.map[mlx.pos_y][mlx.pos_x] = '0';
	mlx_key_hook(mlx.win, sl_movement, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

int	main(void)
{
	so_long();
	return(0);
}
