/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:13 by anvoets           #+#    #+#             */
/*   Updated: 2023/07/19 17:46:15 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	av_print_tab(t_vars mlx)
{
	int w;
	int h;

	w = 0;
	h = 0;
	// ft_printf(" PRINT_TAB\n");
	while (mlx.map[h])
	{
		ft_printf("[%d]%s\n", h, mlx.map[h]);
		h++;
	}
	return (0);
}

int	print_key(int keycode, t_vars mlx)
{
	static int	count;
	t_p_pos		pos;
	// pos.x = sl_pos_calc(mlx, 'h', 'P');
	// pos.y = sl_pos_calc(mlx, 'w', 'P');
	count++;
	// ft_printf("CURRENT PLAYER POS [%d][%d]\n", sl_pos_calc(mlx, 'h', 'P'), sl_pos_calc(mlx, 'w', 'P'));
	if (keycode == 53)
		exit(3);
	if (keycode == 126)
	{
		// mlx.map[pos.x][pos.y] = '0';
		// mlx.map[pos.x - 1][pos.y] = 'P';
		return(sl_map_gen(mlx));
		ft_printf("UP!\n");
	}
	if (keycode == 123)
	{
		ft_printf("LEFT!\n");
	}
	if (keycode == 124)
	{
		ft_printf("RIGHT!\n");
	}
	if (keycode == 125)
	{
		ft_printf("DOWN!\n");
	}
	// sl_test(mlx);
	ft_printf("steps:%d code:[%d]\n", count, keycode);
	return (0);
}

char	*sl_index(char type, t_vars mlx)
{
	if (type == '1')
		return (mlx.tex_wall);
	if (type == '0')
		return (mlx.tex_floor);
	if (type == 'P')
		return (mlx.tex_p_n);
	else
		return (mlx.tex_temp);
	return (0);
}

int	sl_map_gen(t_vars mlx)
{
	t_p_pos		pos;
	// pos.x = sl_pos_calc(mlx, 'h', 'P');
	// pos.y = sl_pos_calc(mlx, 'w', 'P');
	int	h;
	int w;
	h = 0;
	w = 0;
	while (mlx.map[h])
	{
		if (mlx.map[h][w] != '\0')
			mlx_put_image_to_window(mlx.mlx, mlx.win, sl_index(mlx.map[h][w], mlx), w * 100, h * 100);
		if (mlx.map[h][w] == '\0')
		{
			w = 0;
			h++;
		}
		else
			w++;
	}
	return (0);
}

int	main(void)
{
	t_vars	mlx;
	int	win_w = 0;
	int	win_h = 0;
	int w = 0;
	int h = 0;


	mlx.map = sl_gentab("maps/map1.ber");
	win_w = sl_win_calc(mlx, 'w');
	win_h = sl_win_calc(mlx, 'h');
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, win_w * 100, win_h * 100, "so_long");
	mlx.tex_wall = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/blank.xpm", &w, &h);
	mlx.tex_floor = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/bwtile.xpm", &w, &h);
	mlx.tex_temp = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/warning.xpm", &w, &h);
	mlx.tex_p_n = mlx_xpm_file_to_image(mlx.mlx, "images/player_sprites/p_neutral.xpm", &w, &h);
	mlx_key_hook(mlx.win, print_key, &mlx);
	av_print_tab(mlx);
	// sl_map_gen(mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

