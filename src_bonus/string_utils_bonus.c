/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:57:09 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/21 20:22:47 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

static double	convert_left(char *str)
{
	double	result;

	result = 0;
	while (*str != '.' && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result);
}

static double	convert_right(char *str)
{
	double	result;
	double	factor;

	result = 0;
	factor = 0.1;
	while (*str && *str >= '0' && *str <= '9')
	{
		result += (*str - 48) * factor;
		factor *= 0.1;
		str++;
	}
	return (result);
}

double	ft_atod(char *str)
{
	double	left;
	double	right;
	int		sign;

	sign = 1;
	left = 0;
	right = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	left = convert_left(str);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str == '.')
	{
		str++;
		right = convert_right(str);
	}
	return ((left + right) * sign);
}
