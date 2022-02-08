/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 04:24:01 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:38:14 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot_flower(t_fractol *f, t_env *e)
{
	double n;
	double t;

	n = pow(f->z_r, 6) + pow(f->z_i, 6);
	t = 0;
	while (f->iter++ < e->max_iter && n < 2)
	{
		t = f->z_r;
		f->z_r = pow(f->z_r, 6) - (15 * pow(f->z_r, 4) * pow(f->z_i, 2)) +
			(15 * pow(f->z_r, 2) * pow(f->z_i, 4)) - pow(f->z_i, 6) + f->c_i;
		f->z_i = (6 * pow(t, 5) * f->z_i - 20 * pow(t, 3) *
				pow(f->z_i, 3) + 6 * t * pow(f->z_i, 5)) + f->c_r;
		n = pow(f->z_r, 6) + pow(f->z_i, 6);
	}
}

void		mandelbrot(t_fractol *f, t_env *e)
{
	int n;

	n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (n < 4 && f->iter < e->max_iter)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * f->z_r + f->c_i;
		f->z_r = f->tmp;
		f->iter++;
		n = f->z_r * f->z_r + f->z_i * f->z_i;
	}
}

void		mandel_cube(t_fractol *f, t_env *e)
{
	int n;

	n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (n < 8 && f->iter < e->max_iter)
	{
		f->tmp = f->z_r * f->z_r * f->z_r - 3 *
			f->z_r * f->z_i * f->z_i + f->c_r;
		f->z_i = 3 * f->z_r * f->z_r * f->z_i -
			f->z_i * f->z_i * f->z_i + f->c_i;
		f->z_r = f->tmp;
		f->iter++;
		n = f->z_r * f->z_r + f->z_i * f->z_i;
	}
}

void		julia(t_fractol *f, t_env *e)
{
	int n;

	f->z_r = f->i.x / e->zoom + e->x1 + e->offset.x;
	f->z_i = f->i.y / e->zoom + e->y1 + e->offset.y;
	f->c_r = e->julia.real;
	f->c_i = e->julia.imag;
	n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (n < 4 && f->iter < e->max_iter)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * f->z_r + f->c_i;
		f->z_r = f->tmp;
		f->iter++;
		n = f->z_r * f->z_r + f->z_i * f->z_i;
	}
}

void		julia_cube(t_fractol *f, t_env *e)
{
	int		n;
	t_rng	t;

	f->z_r = f->i.x / e->zoom + e->x1 + e->offset.x;
	f->z_i = f->i.y / e->zoom + e->y1 + e->offset.y;
	f->c_r = e->julia.real;
	f->c_i = e->julia.imag;
	t = (t_rng){.real = 0, .imag = 0};
	n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (n < 4 && f->iter < e->max_iter)
	{
		t = (t_rng){.real = f->z_r, .imag = f->z_i};
		f->z_r = t.real * t.real * t.real - 3 *
			t.real * t.imag * t.imag + f->c_r;
		f->z_i = 3 * t.real * t.real * t.imag -
			t.imag * t.imag * t.imag + f->c_i;
		f->iter++;
		n = f->z_r * f->z_r + f->z_i * f->z_i;
	}
}
