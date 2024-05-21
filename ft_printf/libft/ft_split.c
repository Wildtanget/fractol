/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:17:07 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:10:52 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_sub_strings(char const *s1, char c);
// int main(void)
// {
//     char const  *string;
//     char        **res;
//     char        c;
//     int			i;
// 	i = 0;
//     string = "A B C D";
//     c = ' ';
//     res = ft_split(string, c);
// 	while (res[i])
// 	{
//     	printf("the first substring is %s\n", res[i]);
// 		i++;
// 	}
//     return (0);
//	}

char	**ft_split(char const *s1, char c)
{
	char	**str_arr;
	size_t	length;
	int		i;

	str_arr = malloc(sizeof(char *) * (ft_sub_strings(s1, c) + 1));
	if (str_arr == NULL || s1 == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		if (*s1 == c)
			s1++;
		else
		{
			if (ft_strchr(s1, c) == NULL)
				length = ft_strlen(s1);
			else
				length = ft_strchr(s1, c) - s1;
			str_arr[i] = ft_substr(s1, 0, length);
			i++;
			s1 += length;
		}
	}
	str_arr[i] = NULL;
	return (str_arr);
}

static size_t	ft_sub_strings(char const *s1, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] == c)
			i++;
		if (s1[i] != '\0')
			count++;
		while (s1[i] != c && s1[i] != '\0')
			i++;
	}
	return (count);
}
