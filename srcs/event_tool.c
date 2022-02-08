/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:02:50 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:15:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void zoom(t_env *e, int speed)
{
    e->zoom += speed;
    e->max_iter++;
    do_fractol(e);
}

void change_julia_set(t_env *e)
{
    e->rng == 6 ? e->rng = 0 : e->rng++;
    julias_changes(e);
    do_fractol(e);
}

void move(t_env *e, char c, double m)
{
    if (c == 'x')
        e->offset.x += m;
    else if (c == 'y')
        e->offset.y += m;
    do_fractol(e);
}

void allow_motion_julia(t_env *e)
{
    e->motion == 0 ? (e->motion = 1) : (e->motion = 0);
}

void reset_default(t_env *e)
{
    init_fractal(e);
    e->offset = (t_index){.x = -0.5, .y = 0};
    e->cycle = 20;
    do_fractol(e);
}
