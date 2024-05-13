/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:57:09 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/13 19:37:56 by notahtah         ###   ########.fr       */
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
	left = convert_left(str);
	if (*str == '.')
		str++;
	right = convert_right(str);
	return ((left + right) * sign);
}

double	convert_left(char *str)
{
	double	result;

	result = 0;
	while (*str && *str != '.')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result);
}

double	convert_right(char *str)
{
	double	result;
	int		factor;

	result = 0;
	factor = 10;
	while (*str)
	{
		result = result + (*str - 48) / factor;
		factor = factor * 10;
		str++;
	}
	return (result);
}
