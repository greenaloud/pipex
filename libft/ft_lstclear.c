/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:59:50 by wocho             #+#    #+#             */
/*   Updated: 2021/11/19 21:17:19 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnode;
	t_list	*curnode;

	curnode = *lst;
	if (curnode == NULL)
		return ;
	while (curnode->next != NULL)
	{
		delnode = curnode;
		del(delnode->content);
		curnode = curnode->next;
		free(delnode);
	}
	del(curnode->content);
	free(curnode);
	*lst = NULL;
}
