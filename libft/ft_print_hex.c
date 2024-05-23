/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:36:21 by notahtah          #+#    #+#             */
/*   Updated: 2023/11/02 14:31:22 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_print_lower_hex(int c)
{
	char	*str;
	int		count;

	str = ft_htoa(c);
	count = ft_print_string(str);
	free(str);
	return (count);
}

int	ft_print_upper_hex(int c)
{
	char	*hex;
	size_t	i;
	int		count;

	hex = ft_htoa(c);
	i = -1;
	while (++i < ft_strlen(hex))
		hex[i] = ft_toupper(hex[i]);
	count = ft_print_string(hex);
	free(hex);
	return (count);
}

char	*ft_htoa(int n)
{
	char			*s;
	unsigned int	new;
	int				length;

	if (n < 0)
		new = 4294967295 + n + 1;
	else
		new = n;
	length = ft_hex_length(new);
	s = malloc(sizeof(char) * (length + 1));
	if (!s)
		return (NULL);
	ft_htoa_helper(new, s, length);
	s[length] = '\0';
	return (s);
}

int	ft_hex_length(unsigned int n)
{
	int	length;

	if (n == 0)
		return (1);
	length = 0;
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}

void	ft_htoa_helper(unsigned int n, char *s, int length)
{
	int		i;
	int		last_digit;
	char	*hex_base;

	i = 0;
	hex_base = "0123456789abcdef";
	while (++i <= length)
	{
		last_digit = n % 16;
		s[length - i] = hex_base[last_digit];
		n /= 16;
	}
}
