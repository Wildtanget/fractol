/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:11:57 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:16:57 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
#include "libft.h"
// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*ptr;
// 	char	temp;
// 	char	test1;
// 	char	test2;
// 	char	test3;
// 	head = NULL;
// 	test1 = 'a';
// 	ft_lstadd_front(&head, ft_lstnew((void *)&test1));
// 	test2 = 'b';
// 	ft_lstadd_front(&head, ft_lstnew((void *)&test2));
// 	test3 = 'c';
// 	ft_lstadd_front(&head, ft_lstnew((void *)&test3));
// 	ptr = head;
// 	while (ptr != NULL)
// 	{
// 		temp = *((char *)ptr->content);
// 		printf("The content of this node is '%c'\n", temp);
// 		ptr = ptr->next;
// 	}
// 	return (0);
// }

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
