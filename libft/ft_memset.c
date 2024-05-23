/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:45:03 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:15:20 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	char	test[20] = "This is a test";
// 	ft_memset(test, 'x', 4);
// 	printf("%s\n", test);
// 	return (0);
// }

// Replace n characters of string with c
void	*ft_memset(void *string, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)string;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (string);
}
