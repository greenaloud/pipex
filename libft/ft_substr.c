/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:14:30 by wocho             #+#    #+#             */
/*   Updated: 2021/11/30 19:06:03 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	slen;
	size_t	rlen;
	size_t	idx;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (slen < len)
		rlen = slen;
	else
		rlen = len;
	result = malloc(sizeof (*result) * (rlen + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (s[start] && idx < len)
	{
		result[idx] = s[start];
		start++;
		idx++;
	}
	result[idx] = 0;
	return (result);
}
