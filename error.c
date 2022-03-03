/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:17:39 by wocho             #+#    #+#             */
/*   Updated: 2022/03/03 11:17:41 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void	error_exit(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	argc_error(void)
{
	ft_putstr_fd("pipex: not enough arguments\n", STDERR_FILENO);
	ft_putstr_fd("usage: pipex infile cmd1 cmd2 outfile\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	*open_error(char *path)
{
	int		len;
	char	*result;

	len = 0;
	len += strlen(strerror(errno)) + ft_strlen(path) + 10;
	result = malloc(sizeof (*result) * (len + 1));
	ft_strlcat(result, "pipex: ", len + 1);
	ft_strlcat(result, strerror(errno), len + 1);
	ft_strlcat(result, ": ", len + 1);
	ft_strlcat(result, path, len + 1);
	ft_strlcat(result, "\n", len + 1);
	ft_putstr_fd(result, STDERR_FILENO);
	free(result);
	exit(EXIT_FAILURE);
}