/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:49:51 by wocho             #+#    #+#             */
/*   Updated: 2021/11/19 09:45:44 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			idx;
	unsigned char	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	idx = 0;
	while (idx < count * size)
	{
		*(ptr + idx) = 0;
		idx++;
	}
	return (ptr);
}
