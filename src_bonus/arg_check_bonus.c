/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:44:15 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/23 07:44:15 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

int	check_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fractal->set = MANDELBROT;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0
		&& check_julia(argv[2], argv[3]) == 0)
		fractal->set = JULIA;
	else if (argc == 2 && ft_strncmp(argv[1], "burning_ship", 12) == 0)
		fractal->set = BURNING_SHIP;
	else
	{
		ft_printf("%sInvalid arguments!\n%s", A_RED, A_RESET);
		ft_printf("%sUsage:%s	./fractol mandelbrot\n%s", A_GRAY,
			A_ITA, A_RESET);
		ft_printf("%s%s	./fractol burning_ship\n%s", A_GRAY, A_ITA, A_RESET);
		ft_printf("%s%s	./fractol julia [x] [y]\n%s", A_GRAY, A_ITA, A_RESET);
		return (1);
	}
	return (0);
}

int	check_julia(char *re, char *im)
{
	if (check_number(re) == 1 || check_number(im) == 1)
		return (1);
	return (0);
}

int	check_number(char *num)
{
	int	sign;
	int	point;
	int	i;

	sign = 0;
	point = 0;
	i = 0;
	while (num[i])
	{
		if (num[i] == '.')
			point++;
		if (num[i] == '-')
			sign++;
		if (((num[i] < '0' || num[i] > '9') && num[i] != '.' && num[i] != '-')
			|| point > 1 || sign > 1)
			return (1);
		i++;
	}
	return (0);
}
