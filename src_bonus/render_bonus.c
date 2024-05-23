/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:02:17 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/13 19:51:30 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

void	render(t_fractal *fractal)
{
	double		x;
	double		y;
	t_complex	z;
	double		iter;

	x = -1;
	while (x++ < WIDTH)
	{
		y = -1;
		while (y++ < HEIGHT)
		{
			z.x = (scale_map(x, -2, +2, WIDTH)
					* fractal->scale) + fractal->offset_x;
			z.y = (scale_map(y, 2, -2, HEIGHT)
					* fractal->scale) - fractal->offset_y;
			iter = fractal_selecter(z, fractal);
			if (iter < fractal->iterations && (z.x * z.x) + (z.y * z.y) <= 16)
				place_pixel(fractal, x, y, scale_color(iter, fractal));
			else
				place_pixel(fractal, x, y, BLACK);
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->win_ptr, fractal->img.img, 0, 0);
	display_settings(fractal);
}

double	fractal_selecter(t_complex z, t_fractal *fractal)
{
	double	escape_num;

	escape_num = 0;
	if (fractal->set == MANDELBROT)
		escape_num = mandelbrot(z, fractal);
	else if (fractal->set == BURNING_SHIP)
		escape_num = burning_ship(z, fractal);
	else if (fractal->set == JULIA)
		escape_num = julia(z, fractal);
	return (escape_num);
}

void	place_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img.addr
		+ (y * fractal->img.len + x * (fractal->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double	scale_map(double x, double y_mn, double y_mx, double x_mx)
{
	double	result;
	double	x_mn;

	x_mn = 0;
	result = (x - x_mn) * (y_mx - y_mn);
	result /= (x_mx - x_mn);
	result += y_mn;
	return (result);
}
