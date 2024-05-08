#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 640
# define HEIGHT 640

# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

#define NEON_GREEN 0x39FF14
#define ELECTRIC_BLUE 0x00BFFF
#define HOT_PINK 0xFF69B4
#define DEEP_PURPLE 0x9400D3
#define ACID_YELLOW 0xC2FF00
#define FIERY_ORANGE 0xFF8C00
#define TURQUOISE 0x40E0D0
#define CRIMSON_RED 0xDC143C
#define ROYAL_BLUE 0x4169E1

typedef struct s_rgb {
    int r;
    int g;
    int b;
}   t_rgb;

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
    int     set;
    double  offset_x;
    double  offset_y;
    double  scale;
    int     iterations;
    t_rgb   color;
}   t_fractal;

typedef struct s_complex {
    double x;
    double y;
}   t_complex;

void        init_fractal(t_fractal *fractal);
void        render(t_fractal *fractal);
void        place_pixel(t_fractal *fractal, int x, int y, int color);
int         iterater(t_complex c, t_fractal *fractal);
t_complex   square_complex(t_complex z);
t_complex   sum_complex(t_complex z1, t_complex z2);
void        close_program(t_fractal *fractal);
int         keyhook(int keycode, t_fractal *fractal);
int         mousehook(int button, int x, int y, t_fractal *fractal);
double      map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
void check_arguments(int argc, char **argv, t_fractal *fractal);
int         ft_strncmp(char *s1, char *s2, int length);
void handle_error(int code);
int scale_color(int escape_num, t_fractal *fractal);
t_rgb hex_to_rgb(int color);
void shift_color(int keycode, t_fractal *fractal);
#endif