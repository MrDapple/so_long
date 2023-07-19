/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:38:37 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/11 13:25:33 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// long	ft_printf_nb(long n)
// {
// 	int		buf;
// 	char	*str;

// 	buf = 0;
// 	if (n == -2147483648)
// 	{
// 		buf = write(1, "-2147483648", 11);
// 		if (buf == -1)
// 			return (buf);
// 		return (11);
// 	}
// 	str = ft_itoa(n);
// 	if (!str)
// 	{
// 		free(str);
// 		return (-1);
// 	}
// 	buf = ft_printf_str(str);
// 	if (buf == -1)
// 		return (buf);
// 	return (ft_strlen(str));
// }

static int	av_nb_len(long n)
{
	long	ret;
	long	buf;

	ret = 1;
	buf = n;
	if (buf < 0)
	{
		buf *= -1;
		ret++;
	}
	while (buf >= 10)
	{
		buf = buf / 10;
		ret++;
	}
	return (ret);
}

long	ft_printf_nb(long n)
{
	long	ret;

	ret = av_nb_len(n);
	if (n < 10 && n >= 0)
	{
		if (ft_printf_char(n + '0') == -1)
			return (-1);
	}
	else if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		if (ft_printf_nb(n * -1) == -1)
			return (-1);
	}
	else if (n >= 10)
	{
		if (ft_printf_nb(n / 10) == -1)
			return (-1);
		if (ft_printf_nb(n % 10) == -1)
			return (-1);
	}
	return (ret);
}
