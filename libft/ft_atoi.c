/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:35:52 by wocho             #+#    #+#             */
/*   Updated: 2021/11/16 17:40:06 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	long	prev;

	sign = 1;
	result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		prev = result;
		result = result * 10 + *str - '0';
		if (prev != result / 10 && sign == -1)
			return ((int)LONG_MIN);
		if (prev != result / 10 && sign == 1)
			return ((int)LONG_MAX);
		str++;
	}
	return ((int)(sign * result));
}
