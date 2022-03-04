/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:37 by wocho             #+#    #+#             */
/*   Updated: 2022/03/04 12:02:04 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_OPEN];
	int			len;
	t_list		*head;

	if (buffer[fd] == NULL)
	{
		buffer[fd] = malloc(sizeof (char) * (BUFFER_SIZE + 1));
		if (buffer[fd] == NULL)
			return (NULL);
		buffer[fd][0] = '\0';
		buffer[fd][BUFFER_SIZE] = '\0';
	}
	if (buffer[fd][0] == '\0')
	{
		len = read(fd, buffer[fd], BUFFER_SIZE);
		if (len <= 0)
			return (free_ptr((void **)&buffer[fd]));
		buffer[fd][len] = '\0';
	}
	else
		len = get_length(buffer[fd]);
	head = read_single_line(fd, &buffer[fd], &len);
	if (head == NULL)
		return (NULL);
	return (make_string(head, buffer[fd], len));
}

t_list	*read_single_line(int fd, char **buffer, int *len)
{
	int		val;
	t_list	*new;

	new = lst_new(*buffer);
	if (new == NULL)
		return (NULL);
	if (check_nl(*buffer) == -1)
	{
		val = read(fd, *buffer, BUFFER_SIZE);
		if (val < 0)
			return (free_ptr((void **)&new));
		else if (val > 0)
		{
			(*buffer)[val] = '\0';
			*len += val;
			new->next = read_single_line(fd, buffer, len);
			if (new->next == NULL)
				return (free_ptr((void **)&new));
		}
		else
			free_ptr((void **)buffer);
	}
	return (new);
}

char	*make_string(t_list *node, char *buffer, int len)
{
	char	*cur;
	char	*result;
	t_list	*del;

	result = malloc(sizeof (char) * (len + 1));
	if (result == NULL)
		return (NULL);
	cur = result;
	while (node->next != NULL)
	{
		cur += copy_content(cur, node->content);
		del = node;
		node = node->next;
		free(del);
	}
	copy_last_content(cur, node->content, buffer);
	free(node);
	return (result);
}

void	*free_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}
