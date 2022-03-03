/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:38:41 by wocho             #+#    #+#             */
/*   Updated: 2021/11/20 10:56:14 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				idx;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	idx = 0;
	if (n == 0)
		return (0);
	while (str1[idx] && str2[idx] && str1[idx] == str2[idx] && idx < n - 1)
		idx++;
	return (str1[idx] - str2[idx]);
}
