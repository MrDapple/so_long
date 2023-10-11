/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:47:07 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/11 12:09:59 by anvoets          ###   ########.fr       */
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
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

//	MLX DATA STRUCTURE
typedef struct mlx_vars
{
	void	*win;
	void	*mlx;
	int		win_w;
	int		win_h;
	void	*tex_wall;
	void	*tex_floor;
	void	*tex_p_up;
	void	*tex_p_down;
	void	*tex_p_left;
	void	*tex_p_right;
	void	*tex_collectible;
	void	*tex_closed;
	void	*tex_open;
	void	*tex_trail;
	void	*tex_back;
	char	**map;
	char	**t_map;
	int		found;
	int		player;
	int		collect;
	int		exit;
	int		coll_check;
	int		exit_check;
	int		pos_x;
	int		pos_y;
	int		pos_x_e;
	int		pos_y_e;
}			t_vars;

//	MAP UTILS
char		**sl_gentab(char *map);
int			sl_map_render(t_vars *mlx);
int			sl_rip(char *res, int total, int fd);

//	DISPLAY UTILS
int			sl_display_info(t_vars *mlx, int steps);
char		*sl_strgen_steps(int steps);
char		*sl_strgen_collect(int found, int collect);
char		*sl_collect_gen(char *ret, int collect);
void		*sl_img_back(t_vars *mlx);
char		*sl_strgen_free(char *temp, char *ret);
void		sl_display_succes(void *mlx, void *win, char *str);
int			sl_display_freestop(t_vars *mlx, char *str1, char *str2,
				void *back);

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
int			sl_win_calc(t_vars *mlx, char t);
int			sl_pos_calc(t_vars *mlx, char t, char find);
int			sl_collect_calc(t_vars *mlx, char find);
int			sl_find_calc(t_vars *mlx, char find);

//	CHECKERS
int			sl_is_possible(char **map, int y, int x, t_vars *mlx);
int			sl_check(char **map, int y, int x, char c);
int			sl_checkmap(char **map);
int			sl_checktex(t_vars *mlx);
int			sl_check_tb(char **map, int x);
int			sl_check_val(char check, char *lst);
int			sl_check_input(char *in, char *com);

//	FREE / SECURITY
int			sl_free_stop(t_vars *mlx, int errorcode);
int			sl_destroy_img(t_vars *mlx);
void		sl_free_tab(char **tab);
int			sl_end_x(t_vars *mlx);

#endif
