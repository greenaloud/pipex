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

static void	open_io(int iofd[2], char *infile, char *outfile)
{
	iofd[0] = open(infile, O_RDONLY);
	if (iofd[0] == -1)
		open_error(infile);
	iofd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (iofd[1] == -1)
		open_error(outfile);
}

static void execute_cmd(int	fd[2], char *arg, char **envp, char **paths)
{
	char	*command;
	char	**argv;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork");
	else if (pid == 0)
	{
		// 인자를 파싱할 때 따옴표("~~", '~~')를 만난 경우를 추가적으로 처리해 주어야 한다.
		argv = ft_split(arg, ' ');
		command = get_command(paths, argv[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[2]);
		if (execve(command, argv, envp) == -1)
			error_exit("execve");
	}
	wait(NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		iofd[2];
	int		pipefd[2];
	int		paramfd[3];
	char	**paths;

	if (argc != 5)
		argc_error();
	open_io(iofd, argv[1], argv[argc - 1]);
	if (pipe(pipefd) == -1)
		error_exit("pipe");
	paths = get_paths(envp);
	paramfd[0] = iofd[0];
	paramfd[1] = pipefd[1];
	paramfd[2] = pipefd[0];
	execute_cmd(paramfd, argv[2], envp, paths);
	paramfd[0] = pipefd[0];
	paramfd[1] = iofd[1];
	paramfd[2] = pipefd[1];
	perror("merong");
	execute_cmd(paramfd, argv[3], envp, paths);
	return (0);
}
