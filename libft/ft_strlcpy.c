/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:29:33 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:28:58 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"
// int	main(void)
// {
// 	char	*dst;
// 	char	*src;
// 	size_t	size;
// 	dst = (char *)malloc(sizeof(char) * 20);
// 	src = "Succes";
// 	size = 5;
// 	printf("size = %ld, result = %s\n", ft_strlcpy(dst, src, size), dst);
// 	free(dst);
// 	return (0);
// }

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0 || src == NULL)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
