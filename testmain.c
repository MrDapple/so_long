/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:13 by anvoets           #+#    #+#             */
/*   Updated: 2023/07/21 12:43:23 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	av_print_tab(char **map)
{
	int w;
	int h;

	w = 0;
	h = 0;
	// ft_printf(" PRINT_TAB\n");
	// ft_printf("$WIN_W:[%d] $WIN_H:[%d]\n", mlx.win_w, mlx.win_h);
	while (map[h])
	{
		ft_printf("[%d]%s\n", h, map[h]);
		h++;
	}
	// if (!map)
		// ft_printf("NULL\n");
	// ft_printf("=>[%c]\n", map[0][0]);
	return (0);
}

int	sl_key_1(int keycode, t_vars *mlx)
{
	// static int	count;
	// if (keycode == 53)
	// 	exit(3);
	if (mlx->pressed == 1 && mlx->direct == 126)
	{
		if (mlx->map[mlx->pos_h - 1][mlx->pos_w] == '0')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_floor, (mlx->pos_w) * 100, (mlx->pos_h--) * 100);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_n, (mlx->pos_w) * 100, (mlx->pos_h) * 100);
		}
	}
	if (mlx->pressed == 1 && mlx->direct == 125)
	{
		if (mlx->map[mlx->pos_h + 1][mlx->pos_w] == '0')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_floor, (mlx->pos_w) * 100, (mlx->pos_h++) * 100);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_n, (mlx->pos_w) * 100, (mlx->pos_h) * 100);
		}
	}
	if (mlx->pressed == 1 && mlx->direct == 123)
	{
		if (mlx->map[mlx->pos_h][mlx->pos_w - 1] == '0')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_floor, (mlx->pos_w--) * 100, (mlx->pos_h) * 100);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_n, (mlx->pos_w) * 100, (mlx->pos_h) * 100);
		}
	}
	if (mlx->pressed == 1 && mlx->direct == 124)
	{
		if (mlx->map[mlx->pos_h][mlx->pos_w + 1] == '0')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_floor, (mlx->pos_w++) * 100, (mlx->pos_h) * 100);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_n, (mlx->pos_w) * 100, (mlx->pos_h) * 100);
		}
	}
	return (0);
}

int	sl_move_loop(t_vars *mlx)
{
	// static int	count;
	// if (keycode == 53)
	// 	exit(3);
	if (mlx->pressed == 1 && mlx->direct == 126)
	{
		if (mlx->map[mlx->pos_h - 1][mlx->pos_w] == '0')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_floor, (mlx->pos_w) * 100, (mlx->pos_h--) * 100);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_n, (mlx->pos_w) * 100, (mlx->pos_h) * 100);
		}
	}
	if (mlx->pressed == 1 && mlx->direct == 125)
	{
		if (mlx->map[mlx->pos_h + 1][mlx->pos_w] == '0')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_floor, (mlx->pos_w) * 100, (mlx->pos_h++) * 100);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_n, (mlx->pos_w) * 100, (mlx->pos_h) * 100);
		}
	}
	if (mlx->pressed == 1 && mlx->direct == 123)
	{
		if (mlx->map[mlx->pos_h][mlx->pos_w - 1] == '0')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_floor, (mlx->pos_w--) * 100, (mlx->pos_h) * 100);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_n, (mlx->pos_w) * 100, (mlx->pos_h) * 100);
		}
	}
	if (mlx->pressed == 1 && mlx->direct == 124)
	{
		if (mlx->map[mlx->pos_h][mlx->pos_w + 1] == '0')
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_floor, (mlx->pos_w++) * 100, (mlx->pos_h) * 100);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tex_p_n, (mlx->pos_w) * 100, (mlx->pos_h) * 100);
		}
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
		return (mlx->tex_p_n);
	else
		return (mlx->tex_temp);
	return (0);
}

int	sl_map_gen(t_vars *mlx)
{
	t_p_pos		pos;
	int	h;
	int w;
	h = 0;
	w = 0;
	while (mlx->map[h])
	{
		if (mlx->map[h][w] != '\0')
			mlx_put_image_to_window(mlx->mlx, mlx->win, sl_index(mlx->map[h][w], mlx), w * 100, h * 100);
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

int	sl_keystate(int	keycode, t_vars *mlx)
{
	if (keycode == 53)
		exit (3);
	mlx->direct = keycode;
	mlx->pressed = 1;
	return(0);
}

int	sl_keyoff(int keycode, t_vars *mlx)
{
	if (keycode == 53)
		exit (3);
	mlx->direct = -1;
	mlx->pressed = 0;
	return (0);
}
int	main(void)
{
	t_vars	mlx;
	int	win_w = 0;
	int	win_h = 0;
	int w = 0;
	int h = 0;


	mlx.mlx = mlx_init();
	mlx.map = sl_gentab("maps/map1.ber");
	mlx.win_w = sl_win_calc(&mlx, 'w');
	mlx.win_h = sl_win_calc(&mlx, 'h');
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_w * 100, mlx.win_h * 100, "so_long");
	mlx.tex_wall = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/blank.xpm", &w, &h);
	mlx.tex_floor = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/bwtile.xpm", &w, &h);
	mlx.tex_temp = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/warning.xpm", &w, &h);
	mlx.tex_p_n = mlx_xpm_file_to_image(mlx.mlx, "images/player_sprites/p_neutral.xpm", &w, &h);
	mlx.pos_w = sl_pos_calc(&mlx, 'h', 'P');
	mlx.pos_h = sl_pos_calc(&mlx, 'w', 'P');
	sl_map_gen(&mlx);
	mlx.map[mlx.pos_h][mlx.pos_w] = '0';
	mlx_hook(mlx.win, 02, 0, sl_keystate, &mlx);
	mlx_hook(mlx.win, 03, 0, sl_keyoff, &mlx);
	mlx_key_hook(mlx.win, sl_key_1, &mlx);
	// mlx_loop_hook(mlx.mlx, sl_move_loop, &mlx);
	av_print_tab(mlx.map);
	// av_print_tab(mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

