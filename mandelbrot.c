/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:49:53 by czhang            #+#    #+#             */
/*   Updated: 2019/10/29 20:42:34 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mandelbrot(t_mlx r)
{
	t_mandel	m;
	int			x;
	int			y;

	m.iter_max = 50;
	m.zoom = 100;
	x = -1;
	while (++x < 2.7 * m.zoom)
	{
		y = -1;
		while (++y < 2.4 * m.zoom)
		{
			m.cr = x / m.zoom -2.1;
			m.ci = y / m.zoom - 1.2;
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
				draw_pixel((x / m.zoom) * 800 / 2.7, (y / m.zoom) * 600 / 2.4, -1, r);
			else
				draw_pixel((x / m.zoom) * 800 / 2.7, (y / m.zoom) * 600 / 2.4, m.i * 255 / m.iter_max, r);
		}
	}
	return (1);
}
