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

# define H 4 //104
# define ESC 53 //65307
# define TAB 48 //65289
# define J 38 //106
# define P1 18 //65470
# define P2 19 //65471
# define P3 20 //65472
# define P4 21 //65473
# define P5 23 //65474
# define P6 22 //65475
# define P7 26 //65476
# define P8 28 //
# define P9 25 //
# define P0 29 //
# define C 8 //17
# define N0 82 //38
# define N1 83 //233
# define N2 84 //34
# define N3 85 //39
# define N4 86 //40
# define N5 87 //45
# define N6 88 //232
# define N7 89 //95
# define N8 91 //231
# define N9 92 //119
# define M 41 //119
# define R 15 //114
# define S 1 //115
# define PLUS 44
# define MOINS 24
# define SPACE 49//32
# define G 5//103
# define B 11//98
# define ARROW_LEFT 123 //65363
# define ARROW_DOWN 125//65361
# define ARROW_RIGHT 124//65364
# define ARROW_UP 126//65362
# define UP 115 //112
# define DOWN 119 //109



int deal_key(int key, t_env *e)
{
    printf("%d\n", key);
    key == H ? help_event(e) : 0;
    key == ESC ? ft_exit(e) : 0;
    key == TAB ? switch_pal(e) : 0;
    key == J ? change_julia_set(e) : 0;

    key == P1 ? event_color(0, e) : 0;
    key == P2 ? event_color(1, e) : 0;
    key == P3 ? event_color(2, e) : 0;
    key == P4 ? event_color(3, e) : 0;
    key == P5 ? event_color(4, e) : 0;
    key == P6 ? event_color(5, e) : 0;
    key == P7 ? event_color(6, e) : 0;
    if (key == C)
        e->switc == 0 ? e->switc = 1 : (e->switc = 0);
    key == N0 ? switch_fractal(e, 0) : 0;
    key == N1 ? switch_fractal(e, 1) : 0;
    key == N2 ? switch_fractal(e, 2) : 0;
    key == N3 ? switch_fractal(e, 3) : 0;
    key == N4 ? switch_fractal(e, 4) : 0;
    key == N5 ? switch_fractal(e, 5) : 0;
    key == N6 ? switch_fractal(e, 6) : 0;
    key == N7 ? switch_fractal(e, 7) : 0;
    key == N8 ? switch_fractal(e, 8) : 0;
    key == N9 ? switch_fractal(e, 9) : 0;
    key == M ? allow_motion_julia(e) : 0;
    key == SPACE ? reset_default(e) : 0;
    if (key == S)
    {
        e->smooth == 0 ? e->smooth += 1 : (e->smooth = 0);
        do_fractol(e);
    }
    return (0);
}

int press_event(int key, t_env *e) {
    key == MOINS || key == PLUS ? cycle_usr(key, e) : 0;
    key == R ? rgb_usr(e, 'r') : 0;
    key == G ? rgb_usr(e, 'g') : 0;
    key == B ? rgb_usr(e, 'b') : 0;
    key == ARROW_LEFT ? move(e, 'x', 0.05) : 0;
    key == ARROW_RIGHT ? move(e, 'x', -0.05) : 0;
    key == ARROW_DOWN ? move(e, 'y', 0.05) : 0;
    key == ARROW_UP ? move(e, 'y', -0.05) : 0;
    if (key == UP || key == DOWN)
    {
        key == UP ? e->max_iter += 42 : (e->max_iter -= 42);
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
