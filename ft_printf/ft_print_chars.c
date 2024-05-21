/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:18:57 by notahtah          #+#    #+#             */
/*   Updated: 2023/11/02 14:30:09 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *string)
{
	size_t	i;

	i = -1;
	if (!string)
		return (ft_print_string("(null)"));
	while (string[++i])
		ft_print_char(string[i]);
	return (i);
}

int	ft_print_percent(void)
{
	return (ft_print_char('%'));
}
