/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:31:14 by wocho             #+#    #+#             */
/*   Updated: 2022/03/02 02:05:38 by wocho            ###   ########.fr       */
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

static void	process_error(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

static void	process_child(char *argv, char **envp, char **paths, int pfd[2])
{
	int	ofd;

	ofd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ofd == -1)
		process_error("open");
	dup2(pfd[1], STDOUT_FILENO);
	dup2(ofd, STDIN_FILENO);
	close(pfd[0]);
	close(ofd);
	call_execve();
}

static char	**get_paths(char **envp)
{
	char	*path_line;
	char	**paths;

	path_line = NULL;
	while (!path_line && *envp)
	{
		path_line = ft_strnstr(*envp, "PATH=", 5);
		if (path_line)
			break ;
	}
	return (ft_split(path_line + 5, ':'));
}

int	main(int argc, char *argv[], char *envp[])
{
	int		status;
	int		pfd[2];
	int		filefd[2];
	char	**paths;

	if (argc != 5)
		exit(EXIT_FAILURE);
	if (pipe(pfd) == -1)
		process_error("pipe");
	filefd[0] = open(argv[1], O_RDONLY);
	// exception
	filefd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// exception
	execute_child(
	return (0);
}
