/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:08:33 by wocho             #+#    #+#             */
/*   Updated: 2022/03/04 12:02:14 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BONUS_H
# define UTIL_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "error_bonus.h"
# include "libft.h"

char	*make_command(char *path, char *bin);
char	*get_command(char **paths, char *bin);
char	**get_paths(char **envp);
void	free_paths(char **paths);
void	open_io(char *infile, char *outfile);

#endif