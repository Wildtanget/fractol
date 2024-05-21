/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:59:20 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:29:45 by notahtah         ###   ########.fr       */
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

char	*ft_strrchr(const char *str, int c)
{
	int		length;

	c %= 256;
	length = ft_strlen(str);
	while (length >= 0)
	{
		if (str[length] == c)
			return ((char *)str + length);
		length--;
	}
	if (c == '\0')
		return ((char *)str + length);
	return (NULL);
}
