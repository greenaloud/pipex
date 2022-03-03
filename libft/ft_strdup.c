/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:20:13 by wocho             #+#    #+#             */
/*   Updated: 2021/11/16 18:02:32 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		idx;
	int		size;
	char	*copy;

	size = 0;
	while (s1[size])
		size++;
	copy = malloc(sizeof (*copy) * (size + 1));
	if (copy == NULL)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		copy[idx] = s1[idx];
		idx++;
	}
	copy[idx] = 0;
	return (copy);
}
