/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:46:26 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:54:15 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	char	c;
// 	char	*str;
// 	char	*res;
// 	c = 's';
// 	str = "Test string";
// 	res = ft_strchr(str, c);
// 	printf("The string after '%c' is: %s\n", c, res);
// 	return (0);
// }

char	*ft_strchr(const char *str, int c)
{
	int	i;

	c %= 256;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (c == '\0')
		return ((char *)str + i);
	return (NULL);
}
