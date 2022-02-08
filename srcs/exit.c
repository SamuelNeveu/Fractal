/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:02:21 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:19:46 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error();

int ft_exit(t_env *e)
{
	mlx_destroy_image(e->mlx_ptr, e->img_ptr);
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	//free(e->color);
	free(e);
	exit(EXIT_SUCCESS);
	return (0);
}

void ft_clear_img(t_index winsize, int *img)
{
	int i;

	i = 0;
	while (i < winsize.x * winsize.y)
	{
		if (img[i] != 0)
			img[i] = 0;
		i++;
	}
}
