/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:13 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/09 14:55:30 by anvoets          ###   ########.fr       */
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
	else
		return (mlx->tex_temp);
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
					mlx), w * X_WIDTH, h * X_HEIGHT);
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

int	sl_settex(t_vars *mlx)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	mlx->tex_temp = mlx_xpm_file_to_image(mlx->mlx,
			"images/player_sprites/p_n.xpm", &w, &h);
	mlx->tex_p_up = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_up.xpm", &w, &h);
	mlx->tex_p_down = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_down.xpm", &w, &h);
	mlx->tex_p_left = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_left.xpm", &w, &h);
	mlx->tex_p_right = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/P_right.xpm", &w, &h);
	mlx->tex_wall = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/1.xpm", &w, &h);
	mlx->tex_floor = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/0.xpm", &w, &h);
	mlx->tex_temp = mlx_xpm_file_to_image(mlx->mlx,
			"images/map_textures/warning.xpm", &w, &h);
	mlx->tex_collectible = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/C.xpm", &w, &h);
	mlx->tex_closed = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/E.xpm", &w, &h);
	mlx->tex_open = mlx_xpm_file_to_image(mlx->mlx,
			"images/chars/E_lc.xpm", &w, &h);
	return (0);
}

int	sl_free_stop(t_vars *mlx)
{
	free(mlx->map);
	ft_printf("error\n");
	return (0);
}

int	main(void)
{
	t_vars	mlx;
	int		win_w;
	int		win_h;

	win_w = 0;
	win_h = 0;
	mlx.found = 0;
	mlx.mlx = mlx_init();
	mlx.map = sl_gentab("maps/map4.ber");
	mlx.win_w = sl_win_calc(&mlx, 'w');
	mlx.win_h = sl_win_calc(&mlx, 'h');
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_w * X_WIDTH, mlx.win_h * X_HEIGHT,
			"so_long");
	sl_settex(&mlx);
	mlx.pos_x = sl_pos_calc(&mlx, 'x', 'P');
	mlx.pos_y = sl_pos_calc(&mlx, 'y', 'P');
	mlx.pos_x_e = sl_pos_calc(&mlx, 'x', 'E');
	mlx.pos_y_e = sl_pos_calc(&mlx, 'y', 'E');
	if (sl_is_possible(&mlx) == -1)
		return(sl_free_stop(&mlx));
	sl_collect_calc(&mlx, 'C');
	sl_map_render(&mlx);
	mlx.map[mlx.pos_y][mlx.pos_x] = '0';
	mlx_key_hook(mlx.win, sl_movement, &mlx);
	// av_print_tab(mlx.map);
	mlx_loop(mlx.mlx);
	return (0);
}
