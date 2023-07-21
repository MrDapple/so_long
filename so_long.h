/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:47:07 by anvoets           #+#    #+#             */
/*   Updated: 2023/07/21 12:42:01 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "libftprintf/ft_printf.h"
# include "libftprintf/libft/get_next_line.h"
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
	char	**map;
	int		pos_w;
	int		pos_h;
	int		direct;
	int		pressed;
}			t_vars;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct player_pos
{
	int		x;
	int		y;
}			t_p_pos;

int			sl_move_loop(t_vars *mlx);
int			sl_key_1(int keycode, t_vars *mlx);
// char		*sl_clean_line(char	*str);
char		**sl_gentab(char *map);
int			sl_checkmap(int fd, int w, int h);
int			sl_line_len(char *line, char c, char f);
char		**sl_generate(int fd, int w, int h);
char		*sl_index(char type, t_vars *mlx);
int			sl_win_calc(t_vars *mlx, char t);
int			sl_pos_calc(t_vars *mlx, char t, char find);
int			sl_map_gen(t_vars *mlx);
int			av_print_tab(char **map);
int			sl_strlen(char *str);
int			sl_keystate(int keycode, t_vars *mlx);
int			sl_keyoff(int keycode, t_vars *mlx);
// char		**sl_splitclean(char **tab);

#endif
