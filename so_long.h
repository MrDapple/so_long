/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:47:07 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/27 17:50:08 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//	FOR "get_next_line"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//	SIZE MULTIPLIERS
# define X_W 100
# define X_H 100
# define LIMIT 50

//	INCLUDES
# include "libftprintf/ft_printf.h"
# include "libftprintf/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

// free map and t_map and ... (because they're malloc'd)
// destroy all image textures (act as image free)

//	MLX DATA STRUCTURE
typedef struct mlx_vars
{
	void	*win;
	void	*mlx;
	int		win_w;
	int		win_h;
	void	*tex_wall;
	void	*tex_floor;
	void	*tex_temp;
	void	*tex_p_up;
	void	*tex_p_down;
	void	*tex_p_left;
	void	*tex_p_right;
	void	*tex_ghost_n;
	void	*tex_collectible;
	void	*tex_closed;
	void	*tex_open;
	void	*tex_trail;
	char	**map;
	char	**t_map;
	int		found;
	int		collect;
	int		coll_check;
	int		exit_check;
	int		pos_x;
	int		pos_y;
	int		pos_x_e;
	int		pos_y_e;
}			t_vars;

//	MISC (aka to delete later)
int			av_print_tab(char **map);

//	MAP UTILS
char		**sl_gentab(char *map);
int			sl_map_render(t_vars *mlx);

//	SET VARIABLES / INDEX
int			sl_settex(t_vars *mlx);
int			sl_set_vars(t_vars *mlx, char *map);
char		*sl_index(char type, t_vars *mlx);

//	MOVEMENT
int			sl_movement(int keycode, t_vars *mlx);
int			mv_up(t_vars *mlx);
int			mv_down(t_vars *mlx);
int			mv_left(t_vars *mlx);
int			mv_right(t_vars *mlx);

//	CALCULATIONS
int			sl_line_len(char *line, char c, char f);
int			sl_win_calc(t_vars *mlx, char t);
int			sl_pos_calc(t_vars *mlx, char t, char find);
int			sl_strlen(char *str);
int			sl_collect_calc(t_vars *mlx, char find);

//	CHECKERS
int			sl_is_possible(char **map, int y, int x, t_vars *mlx);
int			sl_check(char **map, int y, int x, char c);
int			sl_checkmap(int fd, int w, int h);

//	FREE / SECURITY
int			sl_free_stop(t_vars *mlx, int errorcode);
int			sl_destroy_img(t_vars *mlx);

#endif
