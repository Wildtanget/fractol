/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:52:09 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/21 17:13:23 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

double	mandelbrot(t_complex c, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	double		z_squared;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		z_squared = (z.x * z.x) + (z.y * z.y);
		if ((z.x * z.x) + (z.y * z.y) > 16)
			return (i + 1 - log(log(sqrt(z_squared))) / log(2.0));
		i++;
	}
	return (fractal->iterations);
}

double	burning_ship(t_complex c, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	double		z_squared;

	c.y *= -1;
	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex_abs(z), c);
		z_squared = (z.x * z.x) + (z.y * z.y);
		if ((z.x * z.x) + (z.y * z.y) > 16)
			return (i + 1 - log(log(sqrt(z_squared))) / log(2.0));
		i++;
	}
	return (fractal->iterations);
}

double	julia(t_complex c, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	double		z_squared;

	i = 0;
	z.x = c.x;
	z.y = c.y;
	while (i < fractal->iterations)
	{
		z = sum_complex(square_complex(z), fractal->julia);
		z_squared = (z.x * z.x) + (z.y * z.y);
		if ((z.x * z.x) + (z.y * z.y) > 16)
			return (i + 1 - log(log(sqrt(z_squared))) / log(2.0));
		i++;
	}
	return (fractal->iterations);
}
