/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:51:26 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:58:04 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"
// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	str1 = "Test";
// 	str2 = ft_strdup(str1);
// 	printf("Str1 is '%s' and str2 is '%s'\n", str1, str2);
// 	free(str2);
// 	return (0);
// }

char	*ft_strdup(const char *str1)
{
	char	*str2;
	size_t	i;

	str2 = malloc(ft_strlen(str1) + 1);
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str1))
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
