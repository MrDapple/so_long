/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:47:07 by anvoets           #+#    #+#             */
/*   Updated: 2023/07/18 13:00:09 by anvoets          ###   ########.fr       */
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
}			t_vars;

typedef struct map_tex
{
	void	*wall;
	void	*floor;
	void	*temp;
}			t_maptex;

int			print_key(int keycode);
char		**sl_gentab(char *map);
int			sl_checkmap(int fd, int w, int h);
int			sl_line_len(char *line, char c, char f);
char		**sl_generate(int fd, int w, int h);

#endif
