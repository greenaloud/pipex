/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:53:42 by wocho             #+#    #+#             */
/*   Updated: 2021/11/16 20:35:43 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				idx;
	unsigned char		ch;
	const unsigned char	*ptr;

	ch = c;
	ptr = (const unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (ptr[idx] == ch)
			return ((void *)(ptr + idx));
		idx++;
	}
	return (0);
}
