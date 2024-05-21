/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:15:17 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:13:17 by notahtah         ###   ########.fr       */
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
// 	str1 = "Test string";
// 	str2 = "Test stop";
// 	length = 7;
// 	printf("The result of ft_strncmp is: %d\n", ft_strncmp(str1, str2, length));
// 	printf("The result of strncmp is: %d\n", strncmp(str1, str2, length));
// 	return (0);
// }

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if ((unsigned char)str1[i] < (unsigned char)str2[i])
			return (-1);
		else if ((unsigned char)str1[i] > (unsigned char)str2[i])
			return (1);
		i++;
	}
	return (0);
}
