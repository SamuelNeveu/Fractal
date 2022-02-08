/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:22:14 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:15:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void *draw_pixel(void *thread)
{
    t_thread *t;
    t_env *e;
    t_index i;

    e = ((t_thread *)thread)->e;
    t = (t_thread *)thread;
    t->start = t->n * WIDTH / THREADS;
    t->end = (t->n + 1) * WIDTH / THREADS;
    i.x = t->start;
    while (i.x < t->end)
    {
        i.y = -1;
        while (++i.y < HEIGHT)
            color_pixel_img(e->img, i, e->size, get_color(e, e->data[(int)i.x][(int)i.y]));
        i.x++;
    }
    pthread_exit(NULL);
    return (NULL);
}

void fractal_algo(t_env *e, t_fractol *f, void (*fract)(t_fractol *, t_env *))
{

    f->c_r = (f->i.x / e->zoom) + e->x1 + e->offset.x;
    f->c_i = (f->i.y / e->zoom) + e->y1 + e->offset.y;
    f->z_r = 0;
    f->z_i = 0;
    f->iter = 0;
    (*fract)(f, e);
}

void *fractol_pixel_wheel(void *thread)
{
    t_fractol f;
    t_thread *t;
    t_env *e;

    e = ((t_thread *)thread)->e;
    e->f = &f;
    t = (t_thread *)thread;
    t->start = t->n * WIDTH / THREADS;
    t->end = (t->n + 1) * WIDTH / THREADS;
    f.i.x = t->start;
    while (f.i.x < t->end)
    {
        f.i.y = -1;
        while (++f.i.y < HEIGHT)
        {
            fractal_algo(e, &f, t->fractal);
            e->data[(int)f.i.x][(int)f.i.y] = (t_pixel){.c.real = f.z_r, .c.imag = f.z_i, .i = f.iter};
        }
        f.i.x++;
    }
    pthread_exit(NULL);
    return (NULL);
}

void thread_start(t_env *e, void *f(void *))
{
    t_thread t[THREADS];
    int i;

    i = 0;
    while (i < THREADS)
    {
        t[i].n = i;
        t[i].e = e;
        t[i].fractal = ptr_f_choose(e);
        pthread_create(&(t[i]).id, NULL, f, &t[i]);
        i++;
    }
    i = -1;
    while (++i < THREADS)
        pthread_join(t[i].id, NULL);
}

void do_fractol(t_env *e)
{
    ft_clear_img(e->size, e->img);
    if (e->choix != 9)
    {
        thread_start(e, fractol_pixel_wheel);
        thread_start(e, draw_pixel);
    }
    else
        thread_start(e, buddhabrot_thread);
    mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, 0, 0);
    if (e->help == 1)
        display(e);
}
