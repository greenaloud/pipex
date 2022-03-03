/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:21:05 by wocho             #+#    #+#             */
/*   Updated: 2022/03/03 20:21:07 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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