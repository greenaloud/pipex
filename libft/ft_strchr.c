/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:30:22 by wocho             #+#    #+#             */
/*   Updated: 2021/11/16 10:33:40 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		idx;
	char	target;

	idx = 0;
	target = c;
	if (target == 0)
	{
		while (s[idx])
			idx++;
		return ((char *)(s + idx));
	}
	while (s[idx])
	{
		if (s[idx] == target)
			return ((char *)(s + idx));
		idx++;
	}
	return (0);
}
