/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:54:19 by wocho             #+#    #+#             */
/*   Updated: 2021/11/30 18:17:18 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	char	comp;

	comp = (char) c;
	idx = 0;
	while (s[idx])
		idx++;
	while (idx >= 0)
	{
		if (s[idx] == comp)
			return ((char *)(s + idx));
		idx--;
	}
	return (0);
}
