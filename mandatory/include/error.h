/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:40:41 by wocho             #+#    #+#             */
/*   Updated: 2022/03/04 11:59:48 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include "libft.h"

void	error_exit(char *s);
void	argc_error(void);
void	open_error(char *path);

#endif
