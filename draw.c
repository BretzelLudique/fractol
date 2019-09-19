/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:59:29 by czhang            #+#    #+#             */
/*   Updated: 2019/09/19 06:39:02 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_pixel(int x, int y, t_mlx r)
{
	int		*i;

	i = (int *)(r.img.img_str + 4 * x + r.img.size_line * y);
	*i = 0xffffff;
	return (1);
}

void	printz(double complex z)
{
		ft_putstr("z = ");
		bad_ft_putnbrf(creal(z));
		ft_putstr(" + ");
		bad_ft_putnbrf(cimag(z));
		ft_putendl("i");
}

//mandelbrot
int	draw(double complex c, t_mlx r)
{
	int				i;
	double complex	z;

	i = -1;
	z = 0.0 + 0.0 * I;
	while (++i < 100000)
	{
		z = z * z + c;
		draw_pixel(creal(z), cimag(z), r);
	}
	return (0);
}
