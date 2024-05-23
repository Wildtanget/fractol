/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:58:02 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/13 19:09:31 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	scale_color(double escape_num, t_fractal *fractal)
{
	int		hex_color;	
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)escape_num / fractal->iterations;
	r = (int)(fractal->color.r * t);
	g = (int)(fractal->color.g * t);
	b = (int)(fractal->color.b * t);
	hex_color = r << 16 | g << 8 | b;
	return (hex_color);
}

void	shift_color(int keycode, t_fractal *fractal)
{
	if (keycode == XK_1)
		fractal->color = hex_to_rgb(NEON_GREEN);
	else if (keycode == XK_2)
		fractal->color = hex_to_rgb(ELECTRIC_BLUE);
	else if (keycode == XK_3)
		fractal->color = hex_to_rgb(HOT_PINK);
	else if (keycode == XK_4)
		fractal->color = hex_to_rgb(DEEP_PURPLE);
	else if (keycode == XK_5)
		fractal->color = hex_to_rgb(ACID_YELLOW);
	else if (keycode == XK_6)
		fractal->color = hex_to_rgb(FIERY_ORANGE);
	else if (keycode == XK_7)
		fractal->color = hex_to_rgb(TURQUOISE);
	else if (keycode == XK_8)
		fractal->color = hex_to_rgb(CRIMSON_RED);
	else if (keycode == XK_9)
		fractal->color = hex_to_rgb(ROYAL_BLUE);
}

t_rgb	hex_to_rgb(int hex)
{
	t_rgb	color;

	color.r = (hex >> 16) & 0xFF;
	color.g = (hex >> 8) & 0xFF;
	color.b = hex & 0xFF;
	return (color);
}
