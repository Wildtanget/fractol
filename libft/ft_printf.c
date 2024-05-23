/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:07:36 by notahtah          #+#    #+#             */
/*   Updated: 2023/11/02 14:14:06 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	va_start(args, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			count += ft_print_specifier(format[++i], args);
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}

int	ft_print_specifier(int c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (c == 's')
		count = ft_print_string(va_arg(args, char *));
	else if (c == 'p')
		count = ft_print_pointer(va_arg(args, unsigned long int));
	else if (c == 'd' || c == 'i')
		count = ft_print_integer(va_arg(args, int));
	else if (c == 'u')
		count = ft_print_unsigned(va_arg(args, unsigned long int));
	else if (c == 'x')
		count = ft_print_lower_hex(va_arg(args, int));
	else if (c == 'X')
		count = ft_print_upper_hex(va_arg(args, int));
	else if (c == '%')
		count = ft_print_percent();
	return (count);
}
