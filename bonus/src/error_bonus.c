/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:20:45 by wocho             #+#    #+#             */
/*   Updated: 2022/03/04 12:02:08 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"

void	error_exit(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	argc_error(void)
{
	ft_putstr_fd("pipex: not enough arguments\n", 2);
	ft_putstr_fd("usage: pipex infile cmd cmd [cmd...] outfile\n", 1);
	ft_putstr_fd("       pipex here_doc LIMITER cmd cmd [cmd...] outfile\n", 1);
	exit(EXIT_FAILURE);
}

void	open_error(char *path)
{
	int		len;
	char	*result;

	len = ft_strlen(strerror(errno)) + ft_strlen(path) + 10;
	result = malloc(sizeof (*result) * (len + 1));
	result[0] = '\0';
	ft_strlcat(result, "pipex: ", len + 1);
	ft_strlcat(result, strerror(errno), len + 1);
	ft_strlcat(result, ": ", len + 1);
	ft_strlcat(result, path, len + 1);
	ft_strlcat(result, "\n", len + 1);
	ft_putstr_fd(result, STDERR_FILENO);
	free(result);
	exit(EXIT_FAILURE);
}
