/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:57:09 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/13 19:09:28 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int length)
{
	if (s1 == NULL || NULL == s2 || length <= 0)
		return (1);
	while (*s1 == *s2 && length > 0)
	{
		s1++;
		s2++;
		length--;
	}
	return (*s1 - *s2);
}

double	ft_atod(char *str)
{
	double	left;
	double	right;
	int		sign;
	double	factor;

	sign = 1;
	left = 0;
	right = 0;
	factor = 10;
	while (*str == ' ' || *str == '+')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		left = left * 10 + *str - 48;
		str++;
	}
	if (*str == '.')
		str++;
	while (*str)
	{
		right = right + (*str - 48) / factor;
		factor = factor * 10;
		str++;
	}
	return ((left + right) * sign);
}
