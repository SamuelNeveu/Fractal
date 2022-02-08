/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 05:34:34 by saneveu           #+#    #+#             */
/*   Updated: 2020/01/06 16:16:04 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int deal_key(int key, t_env *e)
{
    printf("%d\n", key);
    key == 104 ? help_event(e) : 0;
    key == 65307 ? ft_exit(e) : 0;
    key == 65289 ? switch_pal(e) : 0;
    key == 106 ? change_julia_set(e) : 0;

    key ==  65470 ? event_color(0, e) : 0;
    key == 65471 ? event_color(1, e) : 0;
    key == 65472 ? event_color(2, e) : 0;
    key == 65473 ? event_color(3, e) : 0;
    key == 65474 ? event_color(4, e) : 0;
    key == 65475 ? event_color(5, e) : 0;
    key == 65476 ? event_color(6, e) : 0;
    if (key == 17)
        e->switc == 0 ? e->switc = 1 : (e->switc = 0);
    key == 38 ? switch_fractal(e, 0) : 0;
    key == 233 ? switch_fractal(e, 1) : 0;
    key == 34 ? switch_fractal(e, 2) : 0;
    key == 39 ? switch_fractal(e, 3) : 0;
    key == 40 ? switch_fractal(e, 4) : 0;
    key == 45 ? switch_fractal(e, 5) : 0;
    key == 232 ? switch_fractal(e, 6) : 0;
    key == 95 ? switch_fractal(e, 7) : 0;
    key == 231 ? switch_fractal(e, 8) : 0;
    key == 224 ? switch_fractal(e, 9) : 0;
    key == 119 ? allow_motion_julia(e) : 0;
    key == 32 ? reset_default(e) : 0;
    if (key == 115)
    {
        e->smooth == 0 ? e->smooth += 1 : (e->smooth = 0);
        do_fractol(e);
    }
    return (0);
}

int press_event(int key, t_env *e) {
    key == 65365 || key == 65366 ? cycle_usr(key, e) : 0;
    key == 114 ? rgb_usr(e, 'r') : 0;
    key == 103 ? rgb_usr(e, 'g') : 0;
    key == 98 ? rgb_usr(e, 'b') : 0;
    key == 65363 ? move(e, 'x', 0.05) : 0;
    key == 65361 ? move(e, 'x', -0.05) : 0;
    key == 65364 ? move(e, 'y', 0.05) : 0;
    key == 65362 ? move(e, 'y', -0.05) : 0;
    if (key == 112 || key == 109)
    {
        key == 112 ? e->max_iter += 42 : (e->max_iter -= 42);
        do_fractol(e);
    }
    return (0);
}

void switch_fractal(t_env *e, int c)
{
    if (c == 0)
        e->choix = 0;
    else if (c == 1)
        e->choix = 1;
    else if (c == 2)
        e->choix = 2;
    else if (c == 3)
        e->choix = 3;
    else if (c == 4)
        e->choix = 4;
    else if (c == 5)
        e->choix = 5;
    else if (c == 6)
        e->choix = 6;
    else if (c == 7)
        e->choix = 7;
    else if (c == 8)
        e->choix = 8;
    else if (c == 9)
        e->choix = 9;
    init_fractal(e);
    do_fractol(e);
}
