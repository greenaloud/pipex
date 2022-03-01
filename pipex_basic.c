#include "pipex.h"
#include "util.c"

static char *make_path(char **path, char *arg)
{
	char	*temp;
	char	*command;
	char	**commands;

	commands = ft_split(arg, ' ');
	while (*path)
	{
		temp = ft_strjoin(*path, "/");
		command = ft_strjoin(temp, commands[0]);
		free(temp);
		if (access(command, F_OK) == 0)
		{
			// 2차원 포인터 내부의 1차원 포인터 해제 처리
			free(commands);
			return (command);
		}
		path++;
		free(command);
	}
	// 2차원 포인터 내부의 1차원 포인터 해제 처리
	free(commands);
	return (NULL);
}

static void	process_child(char *argv[], char *envp[], int pfd[2])
{
	int		idx;
	int		fd1;
	char	*paths;
	char	**path;
	char	*command;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		perror("open");
	dup2(pfd[1], STDOUT_FILENO);
	dup2(fd1, STDIN_FILENO);
	close(pfd[0]);
	close(fd1);
	idx = 0;
	paths = NULL;
	while (!paths && envp[idx])
		paths = ft_strnstr(envp[idx++], "PATH=", 5);
	path = ft_split(paths + 5, ':');
	command = make_path(path, argv[2]);
	if (command == NULL)
		write(STDERR_FILENO, "command not found\n", 20);
	if (execve(command, ft_split(argv[2], ' '), envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

static void	process_parent(char *argv[], char *envp[], int pfd[2])
{
	int		idx;
	int		ofile;
	char	*paths;
	char	**path;
	char	*command;

	ofile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ofile < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	dup2(ofile, STDOUT_FILENO);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[1]);
	close(ofile);
	idx = 0;
	paths = NULL;
	while (!paths && envp[idx])
		paths = ft_strnstr(envp[idx++], "PATH=", 5);
	path = ft_split(paths + 5, ':');
	command = make_path(path, argv[3]);
	if (command == NULL)
		write(STDERR_FILENO, "command not found\n", 20);
	if (execve(command, ft_split(argv[3], ' '), envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		status;
	int		pfd[2];
	pid_t	pid;

	if (argc < 5)
		return (1);
	if (pipe(pfd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
		process_child(argv, envp, pfd);
	else
	{
		wait(&status);
		process_parent(argv, envp, pfd);
	}
	return (0);
}
