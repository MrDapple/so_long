/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:59:53 by anvoets           #+#    #+#             */
/*   Updated: 2023/06/21 10:04:32 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 19
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

enum	e_state
{
	YES = 1,
	NO
};

char	*get_next_line(int fd);
size_t	av_check_nl(char *str);
size_t	av_line_len(char *str, char c);
char	*av_line_join(char *s1, char *s2);
char	*av_buff_move(char *buff);
size_t	av_readnclear(int fd, char *buff);
char	*av_gnl_logic(char *buff, long check, char *res, int fd);

#endif