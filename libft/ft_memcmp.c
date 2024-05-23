/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:34:39 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:26:12 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"
// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	size_t	length;
// 	str1 = "Test";
// 	str2 = "Test";
// 	length = 5;
// 	printf("The result of ft_memcmp is: %d\n", ft_memcmp(str1, str2, length));
// 	printf("The result of memcmp is: %d\n", memcmp(str1, str2, length));
// 	return (0);
// }

int	ft_memcmp(const void *str1, const void *str2, size_t num)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = (unsigned char *)str1;
	temp2 = (unsigned char *)str2;
	while (i < num)
	{
		if (temp1[i] < temp2[i])
			return (-1);
		else if (temp1[i] > temp2[i])
			return (1);
		else
			i++;
	}
	return (0);
}
