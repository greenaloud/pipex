/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:40:44 by wocho             #+#    #+#             */
/*   Updated: 2022/03/04 11:56:34 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "error.h"
# include "libft.h"

char	*make_command(char *path, char *bin);
char	*get_command(char **paths, char *bin);
char	**get_paths(char **envp);
void	free_paths(char **paths);

#endif
