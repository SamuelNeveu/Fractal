/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:00:55 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:15:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void switch_pal(t_env *e)
{
    e->usr_color == 5 ? e->usr_color = 0 : e->usr_color++;
    do_fractol(e);
}

void get_pal(t_env *e)
{
    if (e->usr_color == 0)
        colorset0(e);
    else if (e->usr_color == 1)
        colorset1(e);
    else if (e->usr_color == 2)
        colorset2(e);
    else if (e->usr_color == 3)
        colorset3(e);
    else if (e->usr_color == 4)
        colorset4(e);
    else if (e->usr_color == 5)
        colorset5(e);
}

void event_color(int key, t_env *e)
{
    if (key == 0)
        e->style_color = 0;
    else if (key == 1)
    {
        e->r = 0x0f;
        e->g = 0x0f;
        e->b = 0x0f;
        e->style_color = 1;
    }
    else if (key == 2)
    {
        e->r = 210;
        e->g = 66;
        e->b = 113;
        e->style_color = 2;
    }
    else if (key == 3)
    {
        e->r = 0x00;
        e->g = 0xc1;
        e->b = 0xe5;
        e->r2 = 0xbf;
        e->g2 = 0x1e;
        e->b2 = 0x00;
        e->style_color = 3;
    }
    key == 4 ? e->style_color = 4 : 0;
    key == 5 ? e->style_color = 5 : 0;
    key == 6 ? e->style_color = 6 : 0;
    do_fractol(e);
}

void rgb_usr(t_env *e, char c)
{
    if (e->switc == 0)
    {
        if (c == 'r')
            e->r <= 255 ? e->r += 4 : (e->r = 0);
        else if (c == 'g')
            e->g <= 255 ? e->g += 4 : (e->g = 0);
        else if (c == 'b')
            e->b < 255 ? e->b += 4 : (e->b = 0);
    }
    else if (e->switc == 1 && e->style_color == 3)
    {
        if (c == 'r')
            e->r2 <= 255 ? e->r2 += 4 : (e->r2 = 0);
        else if (c == 'g')
            e->g2 <= 255 ? e->g2 += 4 : (e->g2 = 0);
        else if (c == 'b')
            e->b2 < 255 ? e->b2 += 4 : (e->b2 = 0);
    }
    do_fractol(e);
}

void cycle_usr(int k, t_env *e)
{
    if (k == /*65453*/ 69)
        e->cycle <= 2 || e->cycle <= 5 ? e->cycle = 2 : (e->cycle -= 5);
    else if (k == /*65451*/ 78)
        e->cycle > 300 ? e->cycle = 0 : (e->cycle += 5);
    do_fractol(e);
}