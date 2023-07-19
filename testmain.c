/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:13 by anvoets           #+#    #+#             */
/*   Updated: 2023/07/18 13:16:02 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	av_print_tab(char **tab)
{
	int w;
	int h;

	w = 0;
	h = 0;
	while (tab[h][w])
	{
		ft_printf("%c", tab[h][w]);
		if (tab[h][w] == '\n')
		{
			w = 0;
			h++;
		}
		else
			w++;
	}
	return (0);
}
int	print_key(int keycode)
{
	static int	count;

	count++;
	if (keycode == 53)
		exit(3);
	if (keycode == 126)
	{
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
	ft_printf("steps:%d code:[%d]\n", count, keycode);
	return (count);
}

int	sl_map_gen(t_vars mlx, t_maptex tex, char **map)
{
	int	h;
	int w;
	h = 0;
	w = 0;
	av_print_tab(map);
	while (map[h][w])
	{
		if (map[h][w] == '1')
			mlx_put_image_to_window(mlx.mlx, mlx.win, tex.wall, w * 100, h * 100);
		else if (map[h][w] == '0')
			mlx_put_image_to_window(mlx.mlx, mlx.win, tex.floor, w * 100, h * 100);
		if (map[h][w] == '\n')
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
	t_maptex tex;
	t_vars mlx;
	char **map;
	static int	win_w;
	static int	win_h;
	int w = 0;
	int h = 0;

	map = sl_gentab("maps/map1.ber");
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "so_long");
	tex.wall = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/blank.xpm", &w, &h);
	tex.floor = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/bwtile.xpm", &w, &h);
	tex.temp = mlx_xpm_file_to_image(mlx.mlx, "images/map_textures/warning.xpm", &w, &h);
	mlx_key_hook(mlx.win, print_key, &mlx);
	sl_map_gen(mlx, tex, map);
	mlx_loop(mlx.mlx);
	return (0);
}

