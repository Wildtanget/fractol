/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:58:59 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:20:55 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	temp = head;
	lst = lst->next;
	while (lst)
	{
		head->next = ft_lstnew(f(lst->content));
		if (!head->next)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		head = head->next;
		lst = lst->next;
	}
	head->next = NULL;
	return (temp);
}
