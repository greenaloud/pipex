/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:32:15 by wocho             #+#    #+#             */
/*   Updated: 2022/03/01 14:14:55 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include "../libft/libft.h"

void	error_exit(char *s);
void	argc_error(void);
void	open_error(char *path);

char	*get_command(char **paths, char *bin);
char	*make_command(char *path, char *bin);
char	**get_paths(char **envp);
void	free_paths(char **paths);

#endif
