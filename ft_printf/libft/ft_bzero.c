/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:30:10 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:11:24 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	char	test[20] = "This is a test";
// 	ft_bzero(test, 4);
// 	printf("%s\n", test);
// 	return (0);
// }

void	*ft_bzero(void *string, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)string;
	while (i < n)
	{
		temp[i] = '\0';
		i++;
	}
	return (string);
}
