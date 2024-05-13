/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:27:49 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/13 19:50:54 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

/*=============================================================================
*                                 Window Dimensions
*============================================================================*/
# define WIDTH 640
# define HEIGHT 640

/*=============================================================================
*                                 Fractal Sets
*============================================================================*/

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

/*=============================================================================
*                                 Regular Colors
*============================================================================*/
# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED    	0xFF0000
# define GREEN  	0x00FF00
# define BLUE   	0x0000FF
# define YELLOW 	0xFFFF00
# define CYAN   	0x00FFFF
# define MAGENTA	0xFF00FF

/*=============================================================================
*                                 Psychedelic Colors
*============================================================================*/
# define NEON_GREEN 0x39FF14
# define ELECTRIC_BLUE 0x00BFFF
# define HOT_PINK 0xFF69B4
# define DEEP_PURPLE 0x9400D3
# define ACID_YELLOW 0xC2FF00
# define FIERY_ORANGE 0xFF8C00
# define TURQUOISE 0x40E0D0
# define CRIMSON_RED 0xDC143C
# define ROYAL_BLUE 0x4169E1

/*=============================================================================
*                                 Structures
*============================================================================*/
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_image;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
	int			set;
	int			range;
	double		offset_x;
	double		offset_y;
	double		scale;
	int			iterations;
	t_rgb		color;
	t_complex	julia;
}	t_fractal;

/*=============================================================================
*                                 Function Prototypes
*============================================================================*/

void		close_program(t_fractal *fractal);
void		check_arguments(int argc, char **argv, t_fractal *fractal);
void		handle_error(int code);
void		display_settings(t_fractal *fractal);
/*=============================================================================
*                                 Initialization
*============================================================================*/
void		init_fractal(char **argv, t_fractal *fractal);
void		reset(t_fractal *fractal);

/*=============================================================================
*                                 String Utilities
*============================================================================*/
int			ft_strncmp(char *s1, char *s2, int length);
double		ft_atod(char *str);

/*=============================================================================
*                                 Fractal Functionss
*============================================================================*/
double		mandelbrot(t_complex c, t_fractal *fractal);
double		burning_ship(t_complex c, t_fractal *fractal);
double		julia(t_complex c, t_fractal *fractal);

/*=============================================================================
*                                 Math Utilities
*============================================================================*/
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex_abs(t_complex z);

/*=============================================================================
*                                 Rendering Functions
*============================================================================*/
void		render(t_fractal *fractal);
void		place_pixel(t_fractal *fractal, int x, int y, int color);
double		scale_map(double x, double y_mn, double y_mx, double x_mx);
double		fractal_selecter(t_complex z, t_fractal *fractal);

/*=============================================================================
*                                 Color Functions
*============================================================================*/
int			scale_color(double escape_num, t_fractal *fractal);
t_rgb		hex_to_rgb(int color);
void		shift_color(int keycode, t_fractal *fractal);

/*=============================================================================
*                                 I/O Functions
*============================================================================*/
int			keyhook(int keycode, t_fractal *fractal);
int			mousehook(int button, int x, int y, t_fractal *fractal);

#endif