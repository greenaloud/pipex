/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:48:54 by wocho             #+#    #+#             */
/*   Updated: 2021/11/20 10:43:21 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	while (src[idx] && dstsize && idx < dstsize - 1)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize)
		dst[idx] = 0;
	while (src[idx])
		idx++;
	return (idx);
}
