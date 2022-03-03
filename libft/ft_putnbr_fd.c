/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:21:30 by wocho             #+#    #+#             */
/*   Updated: 2021/11/19 10:33:52 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	long	div;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	else if (nbr == 0)
		write(fd, "0", 1);
	div = 1;
	while (div <= nbr)
		div *= 10;
	div /= 10;
	while (div > 0)
	{
		c = nbr / div + '0';
		nbr %= div;
		div /= 10;
		write(fd, &c, sizeof c);
	}
}
