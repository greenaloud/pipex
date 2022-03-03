/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 05:09:30 by wocho             #+#    #+#             */
/*   Updated: 2021/11/19 09:33:32 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(char *result, long num)
{
	int		idx;
	long	div;

	idx = 0;
	if (num < 0)
	{
		result[idx] = '-';
		num *= -1;
		idx++;
	}
	if (num == 0)
		result[idx++] = '0';
	div = 1;
	while (div <= num)
		div *= 10;
	div /= 10;
	while (div > 0)
	{
		result[idx] = num / div + '0';
		num %= div;
		div /= 10;
		idx++;
	}
	result[idx] = 0;
}

char	*ft_itoa(int n)
{
	int		size;
	int		temp;
	char	*result;

	if (n > 0)
		size = 0;
	else
		size = 1;
	temp = n;
	while (temp != 0)
	{
		size++;
		temp /= 10;
	}
	result = malloc(sizeof (*result) * (size + 1));
	if (result == NULL)
		return (NULL);
	convert(result, n);
	return (result);
}
