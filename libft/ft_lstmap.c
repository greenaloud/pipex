/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:30:27 by wocho             #+#    #+#             */
/*   Updated: 2021/11/30 16:28:50 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*curnode;

	first = ft_lstnew(f(lst->content));
	curnode = first;
	while (lst->next != NULL)
	{
		curnode->next = ft_lstnew(f(lst->next->content));
		if (curnode->next == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		curnode = curnode->next;
		lst = lst->next;
	}
	return (first);
}
