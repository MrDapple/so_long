/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:31:13 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/10 14:59:22 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
	{
		free (tab[i]);
		i--;
	}
	free (tab);
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

	if (argc != 2 || (sl_check_input(argv[1], ".ber") == 0))
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
	if (sl_display_info(&mlx, 0) != 1)
		sl_free_stop(&mlx, 3);
	mlx.map[mlx.pos_y][mlx.pos_x] = '0';
	mlx_key_hook(mlx.win, sl_movement, &mlx);
	mlx_hook(mlx.win, 17, 0, sl_end_x, &mlx);
	mlx_loop(mlx.mlx);
	sl_free_stop(&mlx, 4);
	return (0);
}
