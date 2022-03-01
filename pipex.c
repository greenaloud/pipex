/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:31:14 by wocho             #+#    #+#             */
/*   Updated: 2022/03/01 17:12:29 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "util.c"

static void	logic(int ifd, int ofd, char *av[], char *env[])
{
	execve(
	return ;
}

static char	*make_err_msg(char *s1, char *s2, char *s3)
{
	char	*result;
	size_t	len;

	len = 5;
	len += ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	result = malloc(sizeof (*result) * (len + 1));
	ft_strlcat(result, s1, len + 1);
	ft_strlcat(result, ": ", len + 1);
	ft_strlcat(result, s2, len + 1);
	ft_strlcat(result, ": ", len + 1);
	ft_strlcat(result, s3, len + 1);
	ft_strlcat(result, "\n", len + 1);
	return (result);
}

static void	check_fd(int fd, char *proc, char *target)
{
	char	*err_msg;

	if (fd < 0)
	{
		err_msg = make_err_msg(proc, strerror(errno), target); 
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
		free(err_msg);
		exit(EXIT_FAILURE);
	}
	return ;
}	

int	main(int ac, char *av[], char *env[])
{
	int		ifd;
	int		ofd;

	ifd = open(av[1], O_RDONLY);
	check_fd(ifd, ft_strrchr(av[0], '/') + 1, av[1]);
	ofd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	check_fd(ofd, ft_strrchr(av[0], '/') + 1, av[ac - 1]);

	logic(ifd, ofd, av, env);
	return (0);
}
