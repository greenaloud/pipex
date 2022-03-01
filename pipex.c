/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:31:14 by wocho             #+#    #+#             */
/*   Updated: 2022/02/27 22:43:02 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	logic(int ifd, int ofd, char *av[], char *env[])
{
	return ;
}

int	main(int ac, char *av[], char *env[])
{
	int	ifd;
	int	ofd;

	ifd = open(av[1], O_RDONLY);
	ofd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ifd < 0 || ofd < 0)
	{
		perror("open: ");
		return (-1);
	}
	logic(ifd, ofd, av, env);
	return (0);
}
