/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:28:58 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:25:37 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	char	c;
// 	char	*str;
// 	char	*res;
// 	size_t	size;
// 	c = 's';
// 	str = "Test string";
// 	size = 4;
// 	res = ft_memchr(str, c, size);
// 	printf("The string after '%c' is: %s\n", c, res);
// 	return (0);
// }

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)str;
	while (i < n)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
