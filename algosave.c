/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:24:01 by saneveu           #+#    #+#             */
/*   Updated: 2019/05/28 08:42:34 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_flower(t_fractol *f, t_env *e)
{
	double	n;
	double	t;

	n = pow(f->z_r, 6) + pow(f->z_i, 6);
	t = 0;
	while (f->iter++ < e->max_iter && n < 2)
	{
		t = f->z_r;
		f->z_r = pow(f->z_r, 6) - (15 * pow(f->z_r, 4) * pow(f->z_i, 2))
		+ (15 * pow(f->z_r, 2) * pow(f->z_i, 4)) - pow(f->z_i, 6) + f->c_i;
		f->z_i = (6 * pow(t, 5) * f->z_i - 20 * pow(t, 3) * pow(f->z_i, 3)
		+ 6 * t * pow(f->z_i, 5)) + f->c_r;
		n = pow(f->z_r, 6) + pow(f->z_i, 6);
        if (n > 4)
            e->iter_max = f->iter;
    }
}

void     mandelbrot(t_fractol *f, t_env *e)
{
    int n;

    n = f->z_r * f->z_r + f->z_i * f->z_i; 
    while(n < 4 && f->iter < e->max_iter)
    {
        f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
        f->z_i = 2 * f->z_i * f->z_r + f->c_i;
        f->z_r = f->tmp;
        f->iter++;
        n = f->z_r * f->z_r + f->z_i * f->z_i;
        n > 4 ? e->iter_max = f->iter : 0;
    }
}

void     mandel_cube(t_fractol *f, t_env *e)
{
    int n;

    n = f->z_r * f->z_r + f->z_i * f->z_i;
    while((f->z_r * f->z_r + f->z_i * f->z_i) < 8 && f->iter < e->max_iter)
    {
        f->tmp = f->z_r * f->z_r * f->z_r - 3 * f->z_r * f->z_i * f->z_i + f->c_r;
        f->z_i = 3 * f->z_r * f->z_r * f->z_i - f->z_i * f->z_i * f->z_i + f->c_i;
        f->z_r = f->tmp;
        f->iter++;
        n = f->z_r * f->z_r + f->z_i * f->z_i;
        n > 8 ? e->iter_max = f->iter : 0;
    } 
}

void     julia(t_fractol *f, t_env *e)
{
    int n;
    
    f->z_r = f->i.x / e->zoom + e->x1 + e->offset.x;
    f->z_i = f->i.y / e->zoom + e->y1 + e->offset.y;
    f->c_r = e->julia.real;
    f->c_i = e->julia.imag;
    n = f->z_r * f->z_r + f->z_i * f->z_i;
    while(n < 4 && f->iter < e->max_iter)
    {
        f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
        f->z_i = 2 * f->z_i * f->z_r + f->c_i;
        f->z_r = f->tmp;
        f->iter++;
        n = f->z_r * f->z_r + f->z_i * f->z_i;
        n > 4 ? e->iter_max = f->iter : 0;   
    }
}

void    julia_cube(t_fractol *f, t_env *e)
{
    int n;
    t_rng t;

    f->z_r = f->i.x / e->zoom + e->x1 + e->offset.x;
    f->z_i = f->i.y / e->zoom + e->y1 + e->offset.y;
    f->c_r = e->julia.real;
    f->c_i = e->julia.imag;
    t = (t_rng){.real = 0, .imag = 0};
    n = f->z_r * f->z_r + f->z_i * f->z_i;
    while(n < 4 && f->iter < e->max_iter)
    {
        t = (t_rng){.real = f->z_r, .imag = f->z_i};
        f->z_r = t.real * t.real * t.real - 3 * t.real * t.imag * t.imag + f->c_r;
        f->z_i = 3 * t.real * t.real * t.imag - t.imag * t.imag * t.imag + f->c_i;
        f->iter++;
        n = f->z_r * f->z_r + f->z_i * f->z_i;
        n > 4 ? e->iter_max = f->iter : 0; 
    } 
}

void    lauren(t_fractol *f, t_env *e)
{
    int n;

    n = f->z_r * f->z_r + f->z_i * f->z_i;
    while((f->z_r * f->z_r + f->z_i * f->z_i) < 4 && f->iter < e->max_iter)
	{
		f->tmp = fabs(f->z_i * f->z_i - f->z_r * f->z_r) + f->c_r;
		f->z_r = 2 * f->z_i * f->z_r + f->c_i;
		f->z_i = f->tmp;
        f->iter++;
        n = f->z_r * f->z_r + f->z_i * f->z_i;
        n > 4 ? e->iter_max = f->iter : 0;
    }
}

void    burning_ship(t_fractol *f, t_env *e)
{
    int n;

    n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (f->iter++ < e->max_iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
    {
        f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = fabs(2 * f->z_r * f->z_i) + f->c_i;
		f->z_r = f->tmp;
        n = f->z_r * f->z_r + f->z_i * f->z_i;
        n > 4 ? e->iter_max = f->iter : 0;
    }
}

void	phoenix(t_fractol *f, t_env *e)
{
	double	ti;
    double  tr;
    double  zi_old;
    double  zr_old;
    int     n;

    zi_old = 0;
    zr_old = 0;
    n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (f->iter++ < e->max_iter && n < 8)
	{
        ti = 2 * f->z_r * f->z_i + f->c_i * zi_old;
        tr = f->z_r * f->z_r - (f->z_i * f->z_i) + f->c_i * zr_old + f->c_r;
        zr_old = f->z_r;
        zi_old = f->z_i;
        f->z_r = tr;
        f->z_i = ti;

        n = f->z_r * f->z_r + f->z_i * f->z_i;
        n > 4 ? e->iter_max = f->iter: 0;
	}
}

/*
void	phoenix115621(t_fractol *f, t_env *e)
{
	double	ti;
    double  tr;

    f.z_r = 0;
    f.z_i = 0;
	while (f.iter++ < e->max_iter && f.z_r * f.z_r + f.z_i * f.z_i < 4)
	{
		f.z_i = 2 * f.z_i * f.z_r + f.c_i;
		f.z_r = tr - ti - f.c_r;
        tr = f.z_r * f.z_r;
        ti = f.z_i * f.z_i;
	}
}
*/

void    tricorn(t_fractol *f, t_env *e)
{
    t_rng   old;

    while(f->iter++ > e->max_iter)
    {
        old.real = f->z_r;
		old.imag = f->z_i;
		f->z_r = old.real * old.real - old.imag * old.imag + f->c_r;
		f->z_i = -2 * old.real * old.imag + f->c_i;
		if (f->z_r * f->z_r + f->z_i * f->z_i > 4)
			break ;
    }
}
