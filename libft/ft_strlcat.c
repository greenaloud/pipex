/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 09:53:45 by wocho             #+#    #+#             */
/*   Updated: 2021/11/30 18:08:36 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	di;
	size_t	si;
	size_t	len;

	di = ft_strlen(dst);
	if (di >= dstsize)
		return (dstsize + ft_strlen(src));
	len = di;
	si = 0;
	while (dstsize && di < dstsize - 1)
	{
		if (src[si])
			dst[di] = src[si];
		else
			break ;
		di++;
		si++;
	}
	dst[di] = 0;
	while (src[si])
		si++;
	len += si;
	return (len);
}
