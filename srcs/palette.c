/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:24:03 by saneveu           #+#    #+#             */
/*   Updated: 2019/06/06 16:15:48 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void colorset1(t_env *e)
{
	static int color[16] = {
		0xffff7d,
		0xffee7d,
		0xffdf7e,
		0xffcf7e,
		0xffbf7e,
		0xffaf7e,
		0xff9f7e,
		0xff8f7f,
		0xfe7e7f,
		0xee6f7f,
		0xde5e7f,
		0xce4f7f,
		0xbe3f7f,
		0xae2f7f,
		0x9d1f7f,
		0x8d0e7f};
	e->div = 16;
	e->color = color;
}

void colorset3(t_env *e)
{
	static int color[16] = {
		0xf06d89,
		0xfeaebf,
		0xfbc4d0,
		0xa4ece9,
		0x8fece8,
		0xbeefed,
		0x8fa6ec,
		0xaebeef,
		0xf9cb8a,
		0xf6d19b,
		0xfedfb3,
		0xa39191,
		0xa58d8d,
		0xa17878,
		0xa77070,
	};
	e->div = 16;
	e->color = color;
}

void colorset0(t_env *e)
{
	static int color[16] = {
		65536 * 66 + 256 * 30 + 15,
		65536 * 25 + 256 * 7 + 26,
		65536 * 9 + 256 * 1 + 47,
		65536 * 4 + 256 * 4 + 73,
		65536 * 0 + 256 * 7 + 100,
		65536 * 12 + 256 * 44 + 138,
		65536 * 24 + 256 * 82 + 177,
		65536 * 57 + 256 * 125 + 209,
		65536 * 134 + 256 * 181 + 229,
		65536 * 211 + 256 * 236 + 248,
		65536 * 241 + 256 * 233 + 191,
		65536 * 248 + 256 * 201 + 95,
		65536 * 255 + 256 * 170 + 0,
		65536 * 204 + 256 * 128 + 0,
		65536 * 153 + 256 * 87 + 0,
		65536 * 106 + 256 * 52 + 3};
	e->div = 16;
	e->color = color;
}

void colorset2(t_env *e)
{
	static int color[16] = {
		0xffffff,
		0xdfffff,
		0xbfffff,
		0xa0ffff,
		0x80ffff,
		0x60dfff,
		0x3fbfff,
		0x1f9fff,
		0x7efe,
		0x5edf,
		0x3fbf,
		0x1fa0,
		0x80,
		0x60,
		0x3f,
		0x1f};
	e->div = 16;
	e->color = color;
}

void colorset4(t_env *e)
{
	static int color[16] = {
		0xb2123e,
		0xab1644,
		0xa41a4b,
		0x9d1e51,
		0x952258,
		0x8e265f,
		0x872b65,
		0x802f6c,
		0x783373,
		0x713779,
		0x6a3b80,
		0x633f86,
		0x5c438d,
		0x544794,
		0x4d4b9a,
		0x464fa1,
	};
	e->div = 16;
	e->color = color;
}

void colorset5(t_env *e)
{
	static int color[13] = {
		0x0ee2f5,
		0x0d9df6,
		0x0c58f7,
		0x0b11f7,
		0x4a09f8,
		0x9108f9,
		0xda07fa,
		0xfb06d3,
		0xfc058a,
		0xfd0440,
		0xfd1102,
		0xfe5b01,
		0xffa600,
	};
	e->div = 13;
	e->color = color;
}
