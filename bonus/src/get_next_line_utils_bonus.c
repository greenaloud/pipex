/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:49 by wocho             #+#    #+#             */
/*   Updated: 2022/03/04 12:02:00 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_length(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	check_nl(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int	copy_content(char *dst, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (idx);
}

void	copy_last_content(char *dst, char *src, char *buffer)
{
	int	idx;
	int	pos;

	pos = check_nl(src);
	if (pos != -1)
	{
		idx = 0;
		while (idx <= pos)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
		idx = 0;
		while (src[pos + 1 + idx])
		{
			buffer[idx] = src[pos + 1 + idx];
			idx++;
		}
		buffer[idx] = '\0';
	}
	else
		copy_content(dst, src);
}

t_list	*lst_new(char *str)
{
	t_list	*new;

	new = malloc(sizeof (*new));
	if (new == NULL)
		return (NULL);
	copy_content(new->content, str);
	new->next = NULL;
	return (new);
}
