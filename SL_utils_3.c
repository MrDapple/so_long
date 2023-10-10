/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SL_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:18:43 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/10 12:36:27 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_check_input(char *in, char *com)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (in[c])
	{
		while (in[c] == com[++i])
		{
			if (!in[c])
				return (1);
			c++;
		}
		i = 0;
		if (in[c])
			c++;
	}
	return (0);
}
