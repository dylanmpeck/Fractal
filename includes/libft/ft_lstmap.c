/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:44:42 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/24 18:02:25 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	if (!new)
		return (NULL);
	new = f(lst);
	head = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(lst->content, lst->content_size);
		new->next = f(lst);
		if (!new)
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (head);
}
