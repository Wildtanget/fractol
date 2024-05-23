/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:02:39 by notahtah          #+#    #+#             */
/*   Updated: 2023/11/02 14:29:54 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_print_pointer(unsigned long int ptr)
{
	int		count;
	char	*str;

	if (ptr == 0)
		return (ft_print_string("(nil)"));
	str = ft_ptoa(ptr);
	count = ft_print_string("0x") + ft_print_string(str);
	free(str);
	return (count);
}

char	*ft_ptoa(unsigned long int ptr)
{
	int		length;
	char	*s;
	int		i;
	char	*hex_base;
	int		last_digit;

	length = ft_ptr_length(ptr);
	s = malloc(sizeof(char) * (length + 1));
	if (!s)
		return (NULL);
	i = 0;
	hex_base = "0123456789abcdef";
	while (++i <= length)
	{
		last_digit = ptr % 16;
		s[length - i] = hex_base[last_digit];
		ptr /= 16;
	}
	s[length] = '\0';
	return (s);
}

int	ft_ptr_length(unsigned long int n)
{
	int	length;

	length = 0;
	while (n != 0)
	{
		n /= 16;
		length++;
	}
	return (length);
}
