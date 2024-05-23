/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:00:54 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:38:08 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"
// int	main(void)
// {
// 	char	*big;
// 	char	*little;
// 	big = "This is a test";
// 	little = "test";
// 	printf("The string '%s' is found\n",
// 		ft_strnstr(big, little, ft_strlen(big)));
// 	return (0);
// }

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;

	little_len = ft_strlen(little);
	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < len
			&& big[i + j] != '\0' && little[j] != '\0')
		{
			j++;
			if (j == little_len)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
