/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 07:14:49 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/06 16:06:44 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void display_helper2(t_env *e, char *c, void *m)
{
    if (e->style_color == 3)
    {
        mlx_string_put(m, e->d->win, 200, 290, 0xff0000, "[style 3] |T| to switch rgb");
        mlx_string_put(m, e->d->win, 200, 310, 0xff0000, "-r2 =");
        c = ft_itoa(e->r2);
        mlx_string_put(m, e->d->win, 260, 310, 0x000000, c);
        mlx_string_put(m, e->d->win, 200, 330, 0x00ff00, "-g2 =");
        c = ft_itoa(e->g2);
        mlx_string_put(m, e->d->win, 260, 330, 0x000000, c);
        mlx_string_put(m, e->d->win, 200, 350, 0x0000ff, "-b2 =");
        c = ft_itoa(e->b2);
        mlx_string_put(m, e->d->win, 260, 350, 0x000000, c);
    }
}

void display_helper(t_env *e, char *c, void *m)
{
    mlx_string_put(m, e->d->win, 440, 220, 0x000022, "Cycle =");
    c = ft_itoa(e->cycle);
    mlx_string_put(m, e->d->win, 530, 220, 0x000022, c);
    mlx_string_put(m, e->d->win, 15, 240, 0x000000, "Zoom =");
    c = ft_itoa(e->zoom);
    mlx_string_put(m, e->d->win, 130, 240, 0x000000, c);
    mlx_string_put(m, e->d->win, 15, 260, 0x000000, "Max iter =");
    c = ft_itoa(e->max_iter);
    mlx_string_put(m, e->d->win, 130, 260, 0x000000, c);
    mlx_string_put(m, e->d->win, 15, 280, 0x000022, "Style color =");
    c = ft_itoa(e->style_color);
    mlx_string_put(m, e->d->win, 150, 280, 0x000022, c);
    mlx_string_put(m, e->d->win, 15, 310, 0xff0000, "-r =");
    c = ft_itoa(e->r);
    mlx_string_put(m, e->d->win, 110, 310, 0x000000, c);
    mlx_string_put(m, e->d->win, 15, 330, 0x00ff00, "-g =");
    c = ft_itoa(e->g);
    mlx_string_put(m, e->d->win, 110, 330, 0x000000, c);
    mlx_string_put(m, e->d->win, 15, 350, 0x0000ff, "-b =");
    c = ft_itoa(e->b);
    mlx_string_put(m, e->d->win, 110, 350, 0x000000, c);
    if (e->style_color == 3)
        display_helper2(e, c, m);
}

void display(t_env *e)
{
    void *m;
    char *c;

    m = e->mlx_ptr;
    ft_clear_img(e->d->size, e->d->tab);
    thread_start_sec_win(e, backscreen);
    mlx_put_image_to_window(e->mlx_ptr, e->d->win, e->d->img, 0, 0);
    mlx_string_put(m, e->d->win, 10, 10, 0xFF0000, "*******Keys*******");
    mlx_string_put(m, e->d->win, 15, 50, 0x000000, "1 -> 7 : Color STYLE         PAD NUM : Fractal choice");
    mlx_string_put(m, e->d->win, 15, 70, 0x000000, "Arrows : Move");
    mlx_string_put(m, e->d->win, 15, 90, 0x000000, "+ & - : Cycle Color          Up & Down : Iteration max");
    mlx_string_put(m, e->d->win, 15, 110, 0x000000, "[JULIA] J : change julia set const");
    mlx_string_put(m, e->d->win, 15, 130, 0x000000, "[JULIA] M : Allow mouse motion");
    mlx_string_put(m, e->d->win, 15, 150, 0x000000, "[STYLE 1->3] R - G - B : respectively r g b colors");
    mlx_string_put(m, e->d->win, 15, 170, 0x000000, "S : Smooth color             D : Set default");
    mlx_string_put(m, e->d->win, 10, 200, 0x000fff, "*******Current params*******");
    mlx_string_put(m, e->d->win, 15, 220, 0x000000, "[STYLE 0] Color panel =");
    c = ft_itoa(e->usr_color);
    mlx_string_put(m, e->d->win, 250, 220, 0x000022, c);
    mlx_string_put(m, e->d->win, 300, 220, 0x000022, "Smooth =");
    c = ft_itoa(e->smooth);
    mlx_string_put(m, e->d->win, 380, 220, 0x000022, c);
    display_helper(e, c, m);
    free(c);
}

void *backscreen(void *thread)
{
    t_index i;
    t_thread *t;
    t_env *e;

    e = ((t_thread *)thread)->e;
    t = (t_thread *)thread;
    t->start = t->n * e->d->size.x / 8;
    t->end = (t->n + 1) * e->d->size.x / 8;
    i.x = t->start;
    while (i.x < t->end)
    {
        i.y = -1;
        while (++i.y < e->d->size.y)
        {
            if (e->choix == 9)
                color_pixel_img(e->d->tab, i, e->d->size, rgb_to_hsv(ft_lerpi(0x42, 0x45, i.x), ft_lerpi(0x86, 0xf4, i.x), ft_lerpi(0xf4, 42, i.x)));
            else if (e->style_color == 0)
                color_pixel_img(e->d->tab, i, e->d->size, e->color[(int)((i.x * i.y) / 10000) % e->div]);
            else if (e->style_color == 1)
                color_pixel_img(e->d->tab, i, e->d->size, rgb_to_hsv(e->r + (i.x * i.y) / 100, e->g + (i.x * i.y) / 100, e->b + (i.x * i.y) / 100));
            else if (e->style_color == 2)
                color_pixel_img(e->d->tab, i, e->d->size, rgb_to_hsv(e->r, e->g, e->b));
            else if (e->style_color == 3)
                color_pixel_img(e->d->tab, i, e->d->size, rgb_to_hsv(ft_lerpi(e->r, e->r2, i.x / e->d->size.x), ft_lerpi(e->g, e->g2, i.x / e->d->size.x), ft_lerpi(e->b, e->b2, i.x / e->d->size.x)));
            else if (e->style_color == 4)
                color_pixel_img(e->d->tab, i, e->d->size, rgb_to_hsv(ft_lerpi(0x00, 0xff, i.x / e->d->size.x), ft_lerpi(0x00, 0xff, i.x / e->d->size.x), ft_lerpi(0xff, 0xff, i.x / e->d->size.x)));
            else if (e->style_color == 5)
                color_pixel_img(e->d->tab, i, e->d->size, rgb_to_hsv(255, 55, 25));
            else if (e->style_color == 6)
                color_pixel_img(e->d->tab, i, e->d->size, rgb_to_hsv(ft_lerpi(e->r, e->r2, i.x / e->d->size.x * i.y), ft_lerpi(e->g, e->g2, i.x / e->d->size.x * i.y), ft_lerpi(e->b, e->b2, i.x / e->d->size.x * i.y)));
        }
        i.x++;
    }
    pthread_exit(NULL);
    return (NULL);
}

void init_second_win(t_env *e)
{
    e->d->size = (t_index){.x = 600, .y = 500};
    e->d->win = mlx_new_window(e->mlx_ptr, e->d->size.x, e->d->size.y, "Assistant");
    e->d->img = mlx_new_image(e->mlx_ptr, e->d->size.x, e->d->size.y);
    e->d->tab = (int *)mlx_get_data_addr(e->d->img, &e->d->bpp, &e->d->s_l, &e->d->endian);
    e->d->i = 1;
}

void help_event(t_env *e)
{
    e->help == 0 ? e->help = 1 : (e->help = 0);
    if (e->help == 1)
    {
        if (!(e->d = (t_dis *)malloc(sizeof(t_dis))))
            return;
        init_second_win(e);
        display(e);
    }
    else if (e->help == 0)
    {
        mlx_destroy_image(e->mlx_ptr, e->d->img);
        mlx_destroy_window(e->mlx_ptr, e->d->win);
    }
}

void thread_start_sec_win(t_env *e, void *f(void *))
{
    int i;
    t_thread thread[8];

    i = 0;
    while (i < 8)
    {
        thread[i].n = i;
        thread[i].e = e;
        pthread_create(&(thread[i]).id, NULL, f, &thread[i]);
        i++;
    }
    i = -1;
    while (++i < 8)
        pthread_join(thread[i].id, NULL);
}
