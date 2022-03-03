/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:21:09 by wocho             #+#    #+#             */
/*   Updated: 2022/03/03 20:21:11 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*make_command(char *path, char *bin)
{
	int		len;
	char	*command;

	len = ft_strlen(path) + ft_strlen(bin) + 1;
	command = malloc(sizeof (*command) * (len + 1));
	command[0] = '\0';
	ft_strlcat(command, path, len + 1);
	ft_strlcat(command, "/", len + 1);
	ft_strlcat(command, bin, len + 1);
	return (command);
}

char	*get_command(char **paths, char *bin)
{
	char	*command;

	while (*paths)
	{
		command = make_command(*paths, bin);
		if (access(command, F_OK) == 0)
		{
			if (access(command, X_OK) == 0)
				return (command);
			free(command);
			error_exit("access");
		}
		free(command);
		paths++;
	}
	error_exit("access");
	return (NULL);
}

char	**get_paths(char **envp)
{
	char	*path_line;
	char	**paths;

	path_line = NULL;
	while (!path_line && *envp)
	{
		path_line = ft_strnstr(*envp, "PATH=", 5);
		if (path_line)
			break ;
		envp++;
	}
	return (ft_split(path_line + 5, ':'));
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}
