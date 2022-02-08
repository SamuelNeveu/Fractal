/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:20:46 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:15:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int setup(t_env *e)
{
    e->mlx_ptr = mlx_init();
    e->size = (t_index){.x = WIDTH, .y = HEIGHT};
    if (!(e->win_ptr = mlx_new_window(e->mlx_ptr, e->size.x, e->size.y, "Fractol")) ||
        !(e->img_ptr = mlx_new_image(e->mlx_ptr, e->size.x, e->size.y)) ||
        !(e->img = (int *)mlx_get_data_addr(e->img_ptr, &e->bpp, &e->s_l, &e->endian)))
        return (1);
    init_param(e);
    init_fractal(e);
    return (0);
}

void init_param(t_env *e)
{
    e->cycle = 20;
    e->smooth = 0;
    e->offset = (t_index){.x = -0.5, .y = 0};
    e->rng = 0;
    e->motion = 0;
    e->help = 0;
    e->switc = 0;
    e->style_color = 0;
    e->usr_color = 0;
}

void julias_changes(t_env *e)
{
    if (!e->rng)
        e->julia = (t_rng){.real = -0.506667, .imag = 0.520000};
    else if (e->rng == 1)
        e->julia = (t_rng){.real = 0.403333, .imag = 0.273333};
    else if (e->rng == 2)
        e->julia = (t_rng){.real = 0.386667, .imag = 0.103333};
    else if (e->rng == 3)
        e->julia = (t_rng){.real = -0.203333, .imag = -0.696667};
    else if (e->rng == 4)
        e->julia = (t_rng){.real = 0.18, .imag = -0.566667};
    else if (e->rng == 5)
        e->julia = (t_rng){.real = 0.371504, .imag = -0.153893};
    else if (e->rng == 6 || e->choix == 8)
        e->julia = (t_rng){.real = 0.566666, .imag = -0.5};
}

void init_fractal(t_env *e)
{
    if (e->choix == 0)
    {
        e->zoom = 300;
        e->max_iter = 200;
        e->x1 = -2.1;
        e->x2 = 0.6;
        e->y1 = -1.2;
        e->y2 = 1.2;
    }
    else if (e->choix == 1)
    {
        e->zoom = 250;
        e->max_iter = 200;
        e->x1 = -1.9;
        e->x2 = 0.6;
        e->y1 = -1.4;
        e->y2 = 1.2;
    }
    else if (e->choix == 2)
    {
        e->max_iter = 100;
        e->zoom = 200;
        e->x1 = -2.5;
        e->x2 = 0.6;
        e->y1 = -1.9;
        e->y2 = 1.2;
    }
    else if (e->choix == 3)
    {
        e->zoom = 300;
        e->max_iter = 350;
        e->x1 = -1.5;
        e->x2 = 1.15;
        e->y1 = -1.15;
        e->y2 = 1.25;
        julias_changes(e);
    }
    else if (e->choix == 4)
    {
        e->zoom = 300;
        e->max_iter = 200;
        e->x1 = -1.5;
        e->x2 = 1.15;
        e->y1 = -1.15;
        e->y2 = 1.25;
        julias_changes(e);
    }
    else if (e->choix == 5)
    {
        e->max_iter = 200;
        e->zoom = 250;
        e->x1 = -3;
        e->x2 = 1;
        e->y1 = -1.5;
        e->y2 = 1.35;
    }
    else if (e->choix == 6)
    {
        e->zoom = 200;
        e->max_iter = 300;
        e->x1 = -2.5;
        e->x2 = 1.5;
        e->y1 = -1.8;
        e->y2 = 1.4;
    }
    else if (e->choix == 7)
    {
        e->zoom = 300;
        e->max_iter = 300;
        e->x1 = -2.1;
        e->x2 = 0.6;
        e->y1 = -1.8;
        e->y2 = 1;
    }
    else if (e->choix == 8)
    {
        e->zoom = 300;
        e->max_iter = 100;
        e->x1 = -2.1;
        e->x2 = 0.6;
        e->y1 = -1.35;
        e->y2 = 1.2;
        julias_changes(e);
    }
    else if (e->choix == 9)
    {
        e->max_iter = 50;
        e->x1 = -1.7;
        e->y1 = -1.2;
        e->x2 = 2;
        e->y2 = 0.6;
    }
}

void whatfractal(t_env *e, char *name, int ac)
{
    if (ac >= 2)
    {
        if (!ft_strcmp(name, "mandelbrot") || ac == 1)
            e->choix = 0;
        else if (!ft_strcmp(name, "mandel_cube"))
            e->choix = 1;
        else if (!ft_strcmp(name, "mandel_flower"))
            e->choix = 2;
        else if (!ft_strcmp(name, "julia"))
            e->choix = 3;
        else if (!ft_strcmp(name, "julia_cube"))
            e->choix = 4;
        else if (!ft_strcmp(name, "lauren"))
            e->choix = 5;
        else if (!ft_strcmp(name, "tricorn"))
            e->choix = 6;
        else if (!ft_strcmp(name, "burning_ship"))
            e->choix = 7;
        else if (!ft_strcmp(name, "phoenix"))
            e->choix = 8;
        else
        {
            ft_putendl("Not valids arguments.");
            ft_putendl("[mandelbrot] [julia] [julia_cube] [lauren] [burningship]");
            ft_putendl("[phoenix] [tricorn] [mandel_flower] [mandel_cube]");
            exit(EXIT_FAILURE);
        }
    }
}

void *ptr_f_choose(t_env *e)
{
    void (*f)(t_fractol *, t_env *);

    e->choix == 0 ? f = &mandelbrot : 0;
    e->choix == 1 ? f = &mandel_cube : 0;
    e->choix == 2 ? f = &mandelbrot_flower : 0;
    e->choix == 3 ? f = &julia : 0;
    e->choix == 4 ? f = &julia_cube : 0;
    e->choix == 5 ? f = &lauren : 0;
    e->choix == 6 ? f = &tricorn : 0;
    e->choix == 7 ? f = &burning_ship : 0;
    e->choix == 8 ? f = &phoenix : 0;
    return (f);
}
