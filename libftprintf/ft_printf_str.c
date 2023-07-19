/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:38:59 by anvoets           #+#    #+#             */
/*   Updated: 2023/05/11 11:43:30 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	int	i;
	int	buf;

	i = 0;
	buf = 0;
	if (!str)
		return (ft_printf_str("(null)"));
	while (str[i])
	{
		buf = write(1, &str[i], 1);
		if (buf == -1)
			return (buf);
		i++;
	}
	return (i);
}
