/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:47:07 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/02 14:16:41 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "libftprintf/ft_printf.h"
# include "libftprintf/get_next_line.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct mlx_vars
{
	void	*win;
	void	*mlx;
	int		win_w;
	int		win_h;
	void	*tex_wall;
	void	*tex_floor;
	void	*tex_temp;
	void	*tex_p_n;
	void	*tex_ghost_n;
	void	*tex_collectible;
	void	*tex_closed;
	void	*tex_open;
	char	**map;
	int		found;
	int		collect;
	int		pos_w;
	int		pos_h;
	int		pos_w_e;
	int		pos_h_e;
}			t_vars;

typedef struct player_pos
{
	int		x;
	int		y;
}			t_p_pos;

int			sl_movement(int keycode, t_vars *mlx);
char		**sl_gentab(char *map);
int			sl_checkmap(int fd, int w, int h);
int			sl_line_len(char *line, char c, char f);
char		*sl_index(char type, t_vars *mlx);
int			sl_win_calc(t_vars *mlx, char t);
int			sl_pos_calc(t_vars *mlx, char t, char find);
int			sl_map_render(t_vars *mlx);
int			av_print_tab(char **map);
int			sl_strlen(char *str);
int			mv_up(t_vars *mlx);
int			mv_down(t_vars *mlx);
int			mv_left(t_vars *mlx);
int			mv_right(t_vars *mlx);
int			sl_collect_calc(t_vars *mlx, char find);
int			sl_settex(t_vars *mlx);

#endif
