#include "fractol.h"

int main(void)
{
    t_fractal fractal;
    init_fractal(&fractal);
    render(&fractal);
    mlx_hook(fractal.win_ptr, 17, 0, close_program, &fractal);
    mlx_loop(fractal.mlx_ptr);
    return (0);
}

void    init_fractal(t_fractal *fractal)
{
    fractal->mlx_ptr = mlx_init();
    if (!(fractal->mlx_ptr))
    {
        printf("Malloc error!");
        exit(1);
    }
    fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "test");
    if (!(fractal->win_ptr))
    {
        printf("Malloc error!");
        exit(1);
    }
    fractal->img.img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
    if (!(fractal->img.img))
    {
        printf("Malloc error!");
        exit(1);
    }
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp, &fractal->img.len, &fractal->img.endian);
    if (!(fractal->img.addr))
    {
        printf("Malloc error!");
        exit(1);
    }
}

void render(t_fractal *fractal)
{
    double x;
    double y;
    t_complex temp;
    int iterations;
    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            temp.x = -2 + (4 * x / WIDTH);
            temp.y = 2 - (4 * y / HEIGHT);
            iterations = iterater(temp);
            if (iterations < 200)
                place_pixel(fractal, x, y, 0x000000 + 0xFFFFFF * ((double)iterations / 200));
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img.img, 0, 0);
}

void place_pixel(t_fractal *fractal, int x, int y, int color)
{
    char *dst;

    dst = fractal->img.addr + (y * fractal->img.len + x * (fractal->img.bpp / 8));
	*(unsigned int*)dst = color;
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

t_complex square_complex(t_complex z)
{
    t_complex result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}

int iterater(t_complex c)
{
    int iterations = 200;
    int i = 0;
    t_complex z;
    z.x = 0.0;
    z.y = 0.0;

    while (i < iterations)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > 4)
            return (i);
        i++;
    }
    return (iterations);
}

void close_program(t_fractal *fractal)
{
    if (fractal->img.addr)
    {
        mlx_destroy_image(fractal->mlx_ptr, fractal->img.addr);
        free(fractal->img.img);
    }
    if (fractal->win_ptr)
       mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
    exit(0);
}