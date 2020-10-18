/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:49:53 by czhang            #+#    #+#             */
/*   Updated: 2019/11/02 19:19:45 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_values(int mod, t_fract *f)
{
	if (!mod)
	{
		f->mod = 0;
		f->x1 = -3;
		f->x2 = 3;
		f->y1 = -3;
		f->y2 = 3;
		f->iter_max = 50;
		f->cr = 0;
		f->ci = 0;
	}
	return (1);
}

static int	mandel(int x, int y, t_fract f, t_mlx r)
{
	int		i;
	double	tmp;

	f.cr = x * (f.x2 - f.x1) / WIDTH + f.x1;
	f.ci = y * (f.x2 - f.x1) / HEIGHT + f.y1;
	f.zr = 0;
	f.zi = 0;
	i = -1;
	while (f.zr * f.zr + f.zi * f.zi < 4 && ++i < f.iter_max)
	{
		tmp = f.zr;
		f.zr = f.zr * f.zr - f.zi * f.zi + f.cr;
		f.zi = 2 * f.zi * tmp + f.ci;
	}
	if (i == f.iter_max)
		draw_pixel(x, y, 0xffffff, r);
	else
		draw_pixel(x, y, i * 255 / f.iter_max, r);
	return (1);
}

static int	julia(int x, int y, t_fract f, t_mlx r)
{
	int		i;
	double	tmp;

	f.zr = x * (f.x2 - f.x1) / WIDTH + f.x1;
	f.zi = y * (f.x2 - f.x1) / HEIGHT + f.y1;
	i = -1;
	while (f.zr * f.zr + f.zi * f.zi < 4 && ++i < f.iter_max)
	{
		tmp = f.zr;
		f.zr = f.zr * f.zr - f.zi * f.zi + f.cr;
		f.zi = 2 * f.zi * tmp + f.ci;
	}
	if (i == f.iter_max)
		draw_pixel(x, y, 0xffffff, r);
	else
		draw_pixel(x, y, i * 255 / f.iter_max, r);
	return (1);
}

static int	tricorn(int x, int y, t_fract f, t_mlx r)
{
	int		i;
	double	tmp;

	f.cr = x * (f.x2 - f.x1) / WIDTH + f.x1;
	f.ci = y * (f.x2 - f.x1) / HEIGHT + f.y1;
	f.zr = 0;
	f.zi = 0;
	i = -1;
	while (f.zr * f.zr + f.zi * f.zi < 4 && ++i < f.iter_max)
	{
		tmp = f.zr;
		f.zr = f.zr * f.zr - f.zi * f.zi + f.cr;
		f.zi = -2 * f.zi * tmp + f.ci;
	}
	if (i == f.iter_max)
		draw_pixel(x, y, 0xffffff, r);
	else
		draw_pixel(x, y, i * 255 / f.iter_max, r);
	return (1);
}

int			fract(int mod, t_mlx r)
{
	int				x;
	int				y;

	init_values(mod, r.fract);
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
			else if (r.code_f == 3)
				tricorn(x, y, *r.fract, r);
		}
	}
	return (1);
}
