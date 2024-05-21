/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:28:38 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:22:18 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"
// int	main(void)
// {
// 	char	*ptr;
// 	ptr = calloc(5, sizeof(char));
// 	printf("Allocated pointer\n");
// 	free(ptr);
// 	printf("Free'd ptr\n");
// 	return (0);
// }

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nitems * size);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
