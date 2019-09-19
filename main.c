/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 04:44:02 by czhang            #+#    #+#             */
/*   Updated: 2019/09/19 07:56:05 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_mlx	create_mlx(void)
{
	t_mlx	r;

	r.mlx_ptr = mlx_init();
	r.win_ptr = mlx_new_window(r.mlx_ptr, WIDTH, HEIGHT, "TEST");
	r.img.img_ptr = mlx_new_image(r.mlx_ptr, WIDTH, HEIGHT);
	r.img.img_str = mlx_get_data_addr(r.img.img_ptr,
		&r.img.bpp, &r.img.size_line, &r.img.endian);
	return (r);
}

void		update_z(double complex *z, double complex c)
{
	*z = creal(*z) * creal(*z) - cimag(*z) * cimag(*z) + creal(c) + (2 * creal(*z) * cimag(*z) + cimag(c)) * I;
}

static int	module2(double complex c)
{
	int				i;
	double complex	z;

	z = (0.0 + 0.0 * I);
	i = -1;
	while (++i < 200)
	{
		if (i < 10)
			printz(z);
		update_z(&z, c);
//		(a + ib)(a + ib) = aa - bb + 2ab * i
		if (creal(z) * creal(z) + cimag(z) * cimag(z) > 4)
			return (0);
	}
	return (1);
}

double complex	test_arg(int ac, char **av)
{
	double	complex	c;

	if (ac != 4)
	{
		ft_putendl_fd("usage : './fractol 0 c' for mandelbrot", 2);
		return (0);
	}
	if (ft_atoi(av[1]) == 0) //av[1] == 0 -> mandelbrot
	{
		if ((c = ft_atof(av[2]) + ft_atof(av[3]) * I) == 0)
		{
			ft_putendl_fd("c cannot be 0, otherwise there is no draw", 2);
			return (0);
		}
		else if (!module2(c)) //av[2] = param c pour mandelbrot
		{
			ft_putendl_fd("divergent sequence (|z| > 2), please try another parameter (c)", 2);
			return (0);
		}
		printf("main returns c = %f + %fi\n", creal(c), cimag(c));
		return (c);
	}
	return (-12109210);
}

int			main(int ac, char **av)
{
	double complex	c;
	t_mlx			r;

	if (!(c = test_arg(ac, av)))
		return (0);
	r = create_mlx();
	draw(c, r);
	mlx_put_image_to_window(r.mlx_ptr, r.win_ptr, r.img.img_ptr, 0, 0);
	mlx_key_hook(r.win_ptr, interrupt, &r);
	mlx_loop(r.mlx_ptr);
	return (1);
}

/*int				mainfdf(int ac, char **av)
{
	t_mlx	r;
	t_tab	*tab;
	t_tab	*iso;
	double	angle[2];

	if (!test_arg(ac, av))
		return (0);
	if (!(tab = new_tab(0, 0)) || !(read_file(tab, av[1])))
		return (reterr(0, tab, 0));
	angle[0] = ac == 2 ? 0.785398 : M_PI * ft_atoi(av[2]) / 180;
	angle[1] = ac == 2 ? 0.61086524 : M_PI * ft_atoi(av[3]) / 180;
	if (!(iso = new_tab(tab->x_size, tab->y_size))
			|| !tab_coord(iso, tab, angle))
		return (reterr("tab_iso", tab, iso));
	r = create_mlx();
	resize_coord(iso, update_range(iso));
	draw(iso, r);
	ptit_free(tab);
	mlx_put_image_to_window(r.mlx_ptr, r.win_ptr, r.img.img_ptr, 0, 0);
	mlx_key_hook(r.win_ptr, interrupt, &r);
	mlx_loop(r.mlx_ptr);
	ptit_free(tab);
	ptit_free(iso);
	return (0);
}*/
