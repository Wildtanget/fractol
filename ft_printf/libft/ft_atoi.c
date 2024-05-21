/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:44:09 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/18 15:07:37 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stddef.h>
#include "libft.h"

static size_t	ft_count_white(const char *str);
// int	main(void)
// {
// 	char	*str;
// 	str = "  -12312414";
// 	printf("The string is converted to: %d\n", ft_atoi(str));
// 	return (0);
// }

int	ft_atoi(const char *str)
{
	size_t	i;
	int		total;
	int		signs;

	signs = 0;
	i = ft_count_white(str);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		signs++;
	}
	if (signs > 1)
		return (0);
	total = 0;
	while (i < ft_strlen(str) && str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	if (str[ft_count_white(str)] == '-')
		total *= -1;
	return (total);
}

static size_t	ft_count_white(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
	{
		i++;
	}
	return (i);
}
