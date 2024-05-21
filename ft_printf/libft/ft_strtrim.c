/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:17:34 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 22:48:12 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_start_counter(const char *s1, char const *set);
static size_t	ft_end_counter(const char *s1, char const *set);
// int main(void)
// {
//     char const *s1;
//     char const *set;
//     char       *res;
//     s1 = "   xxx   xxx";
//     set = " x";
//     res = ft_strtrim(s1, set);
//     printf("ft_strtrim(%s, %s) results in %s\n", s1, set, res);
//     free(res);
//     return (0);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	size_t	start;
	size_t	end;

	i = 0;
	start = ft_start_counter(s1, set);
	end = ft_end_counter(s1, set);
	if (end == 0)
		start = 0;
	res = malloc(sizeof(char) * (end - start + 1));
	if (res == NULL)
		return (NULL);
	while (start + i < end)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static size_t	ft_start_counter(const char *s1, char const *set)
{
	size_t	i;

	if (s1[0] == '\0')
		return (0);
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static size_t	ft_end_counter(const char *s1, char const *set)
{
	size_t	s1_length;

	if (s1[0] == '\0')
		return (0);
	s1_length = ft_strlen(s1);
	while (ft_strchr(set, s1[s1_length - 1]) != NULL && s1_length != 0)
		s1_length--;
	return (s1_length);
}
