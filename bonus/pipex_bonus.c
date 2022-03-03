/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:20:48 by wocho             #+#    #+#             */
/*   Updated: 2022/03/03 20:21:00 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	open_io(char *infile, char *outfile)
{
	int	infd;
	int	outfd;

	infd = open(infile, O_RDONLY);
	if (infd == -1)
		open_error(infile);
	outfd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfd == -1)
		open_error(outfile);
	dup2(infd, STDIN_FILENO);
	dup2(outfd, STDOUT_FILENO);
	close(infd);
	close(outfd);
}

static int	execute(int rfd, char *arg, char **envp, char **paths)
{
	int		pfd[2];
	char	*command;
	char	**argv;
	pid_t	pid;

	if (pipe(pfd) == -1)
		error_exit("pipe");
	pid = fork();
	if (pid == -1)
		error_exit("fork");
	else if (pid == 0)
	{
		argv = ft_split(arg, ' ');
		command = get_command(paths, argv[0]);
		dup2(rfd, STDIN_FILENO);
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[0]);
		if (execve(command, argv, envp) == -1)
			error_exit("execve");
	}
	close(pfd[1]);
	wait(NULL);
	return (pfd[0]);
}

static void	execute_last(int rfd, char *arg, char **envp, char **paths)
{
	char	*command;
	char	**argv;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork");
	else if (pid == 0)
	{
		argv = ft_split(arg, ' ');
		command = get_command(paths, argv[0]);
		dup2(rfd, STDIN_FILENO);
		if (execve(command, argv, envp) == -1)
			error_exit("execve");
	}
	wait(NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		paramfd[2];
	int		fd_input;
	char	**paths;

	if (argc < 5)
		argc_error();
	paths = get_paths(envp);
	// here_doc 로직 추가하기
	open_io(argv[1], argv[argc - 1]);
	fd_input = STDIN_FILENO;
	i = 2;
	while (i < argc - 2)
		fd_input = execute(fd_input, argv[i++], envp, paths);
	execute_last(fd_input, argv[argc - 2], envp, paths);
	free_paths(paths);
	return (0);
}
