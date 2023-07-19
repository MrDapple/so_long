/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:46:27 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/11 12:53:08 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *format, ...);
int				ft_printf_char(char c);
long			ft_printf_nb(long n);
int				ft_printf_str(char *str);
unsigned long	ft_printf_void(void *adr);
unsigned long	ft_printf_unsigned(unsigned long n);
long			ft_printf_lower_hex(long n);
long			ft_printf_upper_hex(long n);

#endif