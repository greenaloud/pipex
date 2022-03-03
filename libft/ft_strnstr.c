/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:04:48 by wocho             #+#    #+#             */
/*   Updated: 2021/12/08 14:56:48 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	idx = 0;
	while (haystack[idx] != '\0' && idx + n_len <= len)
	{
		if (ft_memcmp(haystack + idx, needle, n_len) == 0)
			return ((char *)(haystack + idx));
		idx++;
	}
	return (NULL);
}
