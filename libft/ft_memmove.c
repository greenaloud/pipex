/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:42:29 by wocho             #+#    #+#             */
/*   Updated: 2021/11/16 21:31:28 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	if (!dst && !src)
		return (0);
	if (dst > src && len)
	{
		idx = len - 1;
		while (idx > 0)
		{
			*((unsigned char *)dst + idx) = *((unsigned char *)src + idx);
			idx--;
		}
		*((unsigned char *)dst + idx) = *((unsigned char *)src + idx);
	}
	else
	{
		idx = 0;
		while (idx < len)
		{
			*((unsigned char *)dst + idx) = *((unsigned char *)src + idx);
			idx++;
		}
	}
	return (dst);
}
