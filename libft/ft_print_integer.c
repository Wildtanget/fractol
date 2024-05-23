/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:45:18 by notahtah          #+#    #+#             */
/*   Updated: 2023/10/24 15:58:54 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_utoa(unsigned int n);
void	ft_utoa_helper(unsigned int n, char *s, int length);
int		ft_unsigned_length(unsigned int n);

int	ft_print_integer(int c)
{
	char	*str;
	int		count;

	str = ft_itoa(c);
	count = ft_print_string(str);
	free(str);
	return (count);
}

int	ft_print_unsigned(unsigned int c)
{
	char	*string;
	int		count;

	string = ft_utoa(c);
	count = ft_print_string(string);
	free(string);
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	char	*s;

	s = malloc(sizeof(char) * (ft_unsigned_length(n) + 1));
	if (s == NULL)
		return (NULL);
	ft_utoa_helper(n, s, ft_unsigned_length(n));
	s[ft_unsigned_length(n)] = '\0';
	return (s);
}

int	ft_unsigned_length(unsigned int n)
{
	int	length;

	if (n == 0)
		return (1);
	length = 0;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

void	ft_utoa_helper(unsigned int n, char *s, int length)
{
	int	i;
	int	last_digit;

	i = 1;
	while (i <= length)
	{
		last_digit = n % 10;
		s[length - i] = (char)(last_digit + 48);
		n /= 10;
		i++;
	}
}
