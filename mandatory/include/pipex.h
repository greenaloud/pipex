/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:32:15 by wocho             #+#    #+#             */
/*   Updated: 2022/03/04 11:59:53 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "util.h"
# include "error.h"
# include "libft.h"
# include "args.h"

void	error_exit(char *s);
void	argc_error(void);
void	open_error(char *path);

char	*get_command(char **paths, char *bin);
char	*make_command(char *path, char *bin);
char	**get_paths(char **envp);
void	free_paths(char **paths);

#endif
