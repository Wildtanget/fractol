/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:29:05 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/24 15:57:11 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
// int	main(void)
// {
// 	char	*string;
// 	char	*sub_string;
// 	string = "This is a test";
// 	sub_string = ft_substr(string, 10, 4);
// 	printf("The original string is '%s' and the substring is '%s'\n",
// 		string, sub_string);
// 	free(sub_string);
// 	return (0);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	i;
	size_t	length;

	length = 0;
	while (start + length < ft_strlen(s) && length < len)
		length++;
	sub_string = malloc(sizeof(char) * (length + 1));
	if (sub_string == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		sub_string[i] = s[start + i];
		i++;
	}
	sub_string[length] = '\0';
	return (sub_string);
}
