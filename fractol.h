#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 640
# define HEIGHT 640

typedef struct s_image {
    void    *img;
    char    *addr;
    int     bpp;
    int     len;
    int     endian;
}   t_image;

typedef struct s_fractal {
    void    *mlx_ptr;
    void    *win_ptr;
    t_image img;
    double  offset_x;
    double  offset_y;
    double  scale;
}   t_fractal;

typedef struct s_complex {
    double x;
    double y;
}   t_complex;

void    init_fractal(t_fractal *fractal);
void    render(t_fractal *fractal);
void    place_pixel(t_fractal *fractal, int x, int y, int color);
int iterater(t_complex c);
t_complex square_complex(t_complex z);
t_complex sum_complex(t_complex z1, t_complex z2);
void close_program(t_fractal *fractal);
int keyhook(int keycode, t_fractal *fractal);
int mousehook(int button, int x, int y, t_fractal *fractal);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
#endif