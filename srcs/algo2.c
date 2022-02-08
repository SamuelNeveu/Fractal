/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:37:44 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:39:07 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		lauren(t_fractol *f, t_env *e)
{
	int n;

	n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (n < 4 && f->iter < e->max_iter)
	{
		f->tmp = fabs(f->z_i * f->z_i - f->z_r * f->z_r) + f->c_r;
		f->z_r = 2 * f->z_i * f->z_r + f->c_i;
		f->z_i = f->tmp;
		f->iter++;
		n = f->z_r * f->z_r + f->z_i * f->z_i;
	}
}

void		burning_ship(t_fractol *f, t_env *e)
{
	int n;

	n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (f->iter++ < e->max_iter && n < 4)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = fabs(2 * f->z_r * f->z_i) + f->c_i;
		f->z_r = f->tmp;
		n = f->z_r * f->z_r + f->z_i * f->z_i;
	}
}

void		flamme(t_fractol *f, t_env *e)
{
	double	ti;
	double	tr;
	double	zi_old;
	double	zr_old;
	int		n;

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
	}
}

void		phoenix(t_fractol *f, t_env *e)
{
	t_rng o;

	f->z_r = (f->i.x / e->zoom) + e->x1 + e->offset.x;
	f->z_i = (f->i.y / e->zoom) + e->y1 + e->offset.y;
	o.real = f->z_r;
	o.imag = f->z_i;
	while (f->iter++ < e->max_iter && f->z_r * f->z_r + f->z_i * f->z_i < 4)
	{
		f->z_i = 2 * fabs(f->z_i * f->z_r) + e->julia.imag;
		f->z_r = o.real - o.imag + e->julia.real;
		o.real = f->z_r * f->z_r + e->julia.real;
		o.imag = f->z_i * f->z_i + e->julia.imag;
	}
}

void		tricorn(t_fractol *f, t_env *e)
{
	int n;

	n = f->z_r * f->z_r + f->z_i * f->z_i;
	while (n < 4 && f->iter < e->max_iter)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = -2 * f->z_i * f->z_r + f->c_i;
		f->z_r = f->tmp;
		f->iter++;
		n = f->z_r * f->z_r + f->z_i * f->z_i;
	}
}
