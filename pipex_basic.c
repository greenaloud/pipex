#include "pipex.h"
#include "util.c"

static char	*join_command(char *path, char *bin)
{
	char	*result;
	size_t	len;

	len = 1;
	len += ft_strlen(path) + ft_strlen(bin);
	result = malloc(sizeof (char) * (len + 1));
	strlcat(result, path);
	strlcat(result, "/");
	strlcat(result, bin);
	return (result);
}

static char *make_path(char **path, char *arg)
{
	char	*command;
	char	**del;
	char	**args;

	del = args;
	args = ft_split(arg, ' ');
	while (*path)
	{
		command = join_command(*path, args[0]);
		free(temp);
		if (access(command, F_OK) == 0)
		{
			while (*del)
				free(*del++);
			free(args);
			free(commands);
			return (command);
		}
		path++;
		free(command);
	}
	while (*del)
		free(*del++);
	free(args);
	free(commands);
	return (NULL);
}

static char **get_paths(char **envp)
{
	char	*line;

	line = NULL;
	while (!line && *envp)
	{
		line = ft_strnstr(*envp, "PATH=", 5);
		if (line)
			break ;
		envp++;
	}
	return (ft_split(line + 5, ':'));
}

static void	process_child(char *argv[], char *envp[], int pfd[2])
{
	int		idx;
	int		fd1;
	char	**path;
	char	*command;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
		perror("open");
	dup2(pfd[1], STDOUT_FILENO);
	dup2(fd1, STDIN_FILENO);
	close(pfd[0]);
	close(fd1);
	path = get_paths(envp);
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
	wait(&status);
	process_parent(argv, envp, pfd);
	return (0);
}
