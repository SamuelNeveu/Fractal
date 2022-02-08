/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 03:08:54 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:15:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color color_helper(int ic1, int ic2, double p)
{
	t_color c;
	t_color c1;
	t_color c2;

	c1.rgb = fill_rgb(ic1);
	c2.rgb = fill_rgb(ic2);
	c.rgb.r = ft_lerp(c1.rgb.r, c2.rgb.r, p);
	c.rgb.g = ft_lerp(c1.rgb.g, c2.rgb.g, p);
	c.rgb.b = ft_lerp(c1.rgb.b, c2.rgb.b, p);
	c.rgb.a = 0x00;
	c.value = rgb_to_hsv(c.rgb.r, c.rgb.g, c.rgb.b);
	return (c);
}

t_color linear_color(t_env *e, t_pixel p, int *c)
{
	double index;

	index = fmod(p.i, e->cycle - 1) / (e->cycle - 1);
	index = index * e->div;
	return (color_helper(c[(int)index + 1], c[(int)index], 0.5));
}

t_color smooth_color(t_env *e, t_pixel p, int *c)
{
	double mult;
	double nu;
	double nu_frac;
	double index;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + e->cycle - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	index = p.i / e->max_iter * 16;
	return (smooth_color_helper(e, index, nu_frac, c));
}

t_color smooth_color_helper(t_env *e, double index, double mu, int *c)
{
	t_color c1;
	t_color c2;
	t_color color;
	int ic1;
	int ic2;

	(void)e;
	ic1 = index;
	ic2 = ic1 + 1;
	c1.rgb = fill_rgb(c[ic1]);
	c2.rgb = fill_rgb(c[ic2]);
	color.rgb.r = ft_lerp(c1.rgb.r, c2.rgb.r, mu);
	color.rgb.g = ft_lerp(c1.rgb.g, c2.rgb.g, mu);
	color.rgb.b = ft_lerp(c1.rgb.b, c2.rgb.b, mu);
	color.value = rgb_to_hsv(color.rgb.r, color.rgb.g, color.rgb.b);
	return (color);
}

int fire(t_pixel p, int iter_max)
{
	t_color s;
	double nu;
	double nu_frac;
	double mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + 3 - log2(log2(sqrt(mult)))) / iter_max;
	nu_frac = nu - (int)nu;
	s.rgb.r = (int)(285 * nu_frac + 70 * nu_frac);
	s.rgb.g = (int)(55 * nu_frac);
	s.rgb.b = (int)(25 * nu_frac);
	return (s.rgb.r << 16 | s.rgb.g << 8 | s.rgb.b);
}