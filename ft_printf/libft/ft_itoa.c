/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:56:09 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/20 23:23:20 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_int_length(int n);
static void		ft_convert(long int n, char *s, int sign, int length);
// int	main(void)
// {
// 	char	*s;
// 	s = ft_itoa(-2147483648);
// 	free(s);
// 	return (0);
// }

char	*ft_itoa(int n)
{
	char	*s;
	int		sign;

	sign = 0;
	if (n < 0)
		sign++;
	s = malloc(sizeof(char) * (ft_int_length(n) + 1 + sign));
	if (s == NULL)
		return (NULL);
	if (sign == 1)
		s[0] = '-';
	ft_convert(n, s, sign, ft_int_length(n));
	s[ft_int_length(n) + sign] = '\0';
	return (s);
}

static int	ft_int_length(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	ft_convert(long int n, char *s, int sign, int length)
{
	int	i;
	int	last_digit;

	i = 1;
	while (i <= length)
	{
		last_digit = n % 10;
		if (last_digit < 0)
			last_digit *= -1;
		s[length - i + sign] = (char)(last_digit + 48);
		n /= 10;
		i++;
	}
}
