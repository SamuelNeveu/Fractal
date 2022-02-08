/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 01:12:21 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:15:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int color_rgb(t_env *e, t_pixel p)
{
	int color;
	int r;
	int g;
	int b;
	double mult;
	double nu;
	double nu_frac;

	color = 0;
	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + e->cycle - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	r = ft_lerpi(e->r, e->r * p.i, nu_frac);
	g = ft_lerpi(e->g, e->g * p.i, nu_frac); //(int)p.i * (e->g * nu_frac);
	b = ft_lerpi(e->b, e->b * p.i, nu_frac); //(int)p.i * (e->b * nu_frac);
	color += r << 16;
	color += g << 8;
	color += b;
	return (color);
}
t_color color_rgb2(t_env *e, t_pixel p)
{
	t_color color;
	double nu;
	double nu_frac;
	double mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + e->cycle - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	color.rgb.r = (nu_frac * 5) * e->r;
	color.rgb.g = (255 - (nu_frac * 10)) * e->g;
	color.rgb.b = (255 - (nu_frac * 2)) * e->b;
	color.value = color.rgb.r << 16 | color.rgb.g << 8 | color.rgb.b;
	return (color);
}

t_color zebre_rgb_psyche(t_env *e, t_pixel p)
{
	t_color color;
	double nu;
	double nu_frac;
	double mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + 5 - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	color.rgb.r = (e->r / nu_frac);
	color.rgb.g = (e->g / nu_frac);
	color.rgb.b = (e->b / nu_frac);
	color.value = color.rgb.r << 16 | color.rgb.g << 8 | color.rgb.b;
	return (color);
}

t_color color_gradiant(t_env *e, t_pixel p)
{
	t_color color;
	double nu;
	double nu_frac;
	double mult;

	mult = p.c.real * p.c.real + p.c.imag * p.c.imag;
	nu = (p.i + e->cycle - log2(log2(sqrt(mult)))) / e->max_iter;
	nu_frac = nu - (int)nu;
	color.rgb.r = ft_lerp(e->r, e->r2, nu_frac);
	color.rgb.g = ft_lerp(e->g, e->g2, nu_frac);
	color.rgb.b = ft_lerp(e->b, e->b2, nu_frac);
	color.value = color.rgb.r << 16 | color.rgb.g << 8 | color.rgb.b;
	return (color);
}

int vasarely(t_pixel p)
{
	if (p.c.imag > 0)
		return (0x000000);
	return (0xFFFFFF);
}
