/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:49:53 by czhang            #+#    #+#             */
/*   Updated: 2019/10/31 18:29:46 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_values(int zoom_level, t_mandel *m)
{
	if (!zoom_level)
	{
		m->zoom_level = 0;
		m->x1 = -2.1;
		m->x2 = 0.6;
		m->y1 = -1.2;
		m->y2 = 1.2;
		m->iter_max = 50;
	}
	return (1);
}

int			mandel(int x, int y, t_mandel m, t_mlx r)
{
	m.cr = x * (m.x2 - m.x1) / WIDTH + m.x1;
	m.ci = y * (m.x2 - m.x1) / HEIGHT + m.y1;
	m.zr = 0;
	m.zi = 0;
	m.i = 0;
	while (m.zr * m.zr + m.zi * m.zi < 4 && m.i < m.iter_max)
	{
		m.tmp = m.zr;
		m.zr = m.zr * m.zr - m.zi * m.zi + m.cr;
		m.zi = 2 * m.zi * m.tmp + m.ci;
		m.i++;
	}
	if (m.i == m.iter_max)
		draw_pixel(x, y, 0xffffff, r);
	else
		draw_pixel(x, y, m.i * 255 / m.iter_max, r);
	return (1);
}

int			julia(int x, int y, t_mandel m, t_mlx r)
{
	m.zr = x * (m.x2 - m.x1) / WIDTH + m.x1;
	m.zi = y * (m.x2 - m.x1) / HEIGHT + m.y1;
	m.cr = 0;
	m.ci = 0;
	m.i = 0;
	while (m.zr * m.zr + m.zi * m.zi < 4 && m.i < m.iter_max)
	{
		m.tmp = m.zr;
		m.zr = m.zr * m.zr - m.zi * m.zi + m.cr;
		m.zi = 2 * m.zi * m.tmp + m.ci;
		m.i++;
	}
	if (m.i == m.iter_max)
		draw_pixel(x, y, 0xffffff, r);
	else
		draw_pixel(x, y, m.i * 255 / m.iter_max, r);
	return (1);
}

int			fract(int zoom_level, t_mlx r)
{
	int				x;
	int				y;

	init_values(zoom_level, r.fract);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (r.code_f == 1)
				julia(x, y, *r.fract, r);
			else if (r.code_f == 2)
				mandel(x, y, *r.fract, r);
			//else if (r.code_f == 2)
		}
	}
	return (1);
}
