/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:48:38 by wocho             #+#    #+#             */
/*   Updated: 2021/11/16 20:33:33 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			idx;

	idx = 0;
	while (idx < len)
	{
		*((unsigned char *)b + idx) = c;
		idx++;
	}
	return (b);
}
