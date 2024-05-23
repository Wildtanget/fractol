/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:16:43 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:15:59 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
#include "libft.h"
// int	main(void)
// {
// 	t_list	*lst_head;
// 	t_list	*ptr;
// 	lst_head = NULL;
// 	ft_lstadd_front(&lst_head, ft_lstnew(1));
// 	ft_lstadd_front(&lst_head, ft_lstnew(2));
// 	ft_lstadd_front(&lst_head, ft_lstnew(3));
// 	ptr = lst_head;
// 	while (ptr != NULL)
// 	{
// 		printf("The content of this node is '%c'\n", ptr->content);
// 		ptr = ptr->next;
// 	}
// 	printf("The size of the list is %d\n", ft_lstsize(lst_head));
// 	return (0);
// }

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	ptr = lst;
	count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
