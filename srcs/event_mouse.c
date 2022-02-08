/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:46:43 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/07 16:28:32 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_zoom(int k, int x, int y, t_env *e)
{
	if ((k == 1 || k == 2 || k == 4 || k == 5) &&
		(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (k == 2)
		{
			e->x1 = (x / e->zoom + e->x1) - (x / (e->zoom / 1.25));
			e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom / 1.25));
			if (e->max_iter >= 200)
				e->max_iter -= 5;
		}
		k == 2 || k == 5 ? e->zoom /= 1.25 : 0;
		if (k == 1)
		{
			e->x1 = (x / e->zoom + e->x1) - (x / (e->zoom * 1.25));
			e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom * 1.25));
			e->max_iter += 21;
		}
		k == 1 || k == 4 ? e->zoom *= 1.25 : 0;
		do_fractol(e);
	}
	return (1);
}

int motion_mouse(int x, int y, t_env *e)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && e->motion)
	{
		e->julia.real = (x / e->zoom) + e->x1 + e->offset.x;
		e->julia.imag = (y / e->zoom) + e->y1 + e->offset.y;
		do_fractol(e);
		//printf("real : %f , imag : %f\n", e->julia.real, e->julia.imag);
		e->opos.x = x % 12;
		e->opos.y = y % 12;
	}
	return (1);
}