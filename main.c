/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 04:44:02 by czhang            #+#    #+#             */
/*   Updated: 2019/10/31 18:23:30 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_mlx	create_mlx(void)
{
	t_mlx		r;
	t_mandel	*m;

	r.mlx_ptr = mlx_init();
	r.win_ptr = mlx_new_window(r.mlx_ptr, WIDTH, HEIGHT, "TEST");
	r.img.img_ptr = mlx_new_image(r.mlx_ptr, WIDTH, HEIGHT);
	r.img.img_str = mlx_get_data_addr(r.img.img_ptr,
			&r.img.bpp, &r.img.size_line, &r.img.endian);
	r.fract = (t_mandel *)malloc(sizeof(t_mandel));
	return (r);
}

int	zoom(int key, int x, int y, t_mlx *r)
{
	double		posx;
	double		posy;

	posx = r->fract->x1 + x * (r->fract->x2 - r->fract->x1) / WIDTH;
	posy = r->fract->y1 + y * (r->fract->y2 - r->fract->y1) / HEIGHT;
	if (key == 1)
	{
		r->fract->zoom_level++;
		r->fract->x1 = posx - (r->fract->x2 - r->fract->x1) / 4;
		r->fract->x2 = posx + (r->fract->x2 - r->fract->x1) / 4;
		r->fract->y1 = posy - (r->fract->y2 - r->fract->y1) / 4;
		r->fract->y2 = posy + (r->fract->y2 - r->fract->y1) / 4;
		fract(r->fract->zoom_level, *r);
		mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->img.img_ptr, 0, 0);
	}
	else if (key == 2)
	{
		r->fract->zoom_level++;
		r->fract->x1 = posx - (r->fract->x2 - r->fract->x1);
		r->fract->x2 = posx + (r->fract->x2 - r->fract->x1);
		r->fract->y1 = posy - (r->fract->y2 - r->fract->y1);
		r->fract->y2 = posy + (r->fract->y2 - r->fract->y1);
		fract(r->fract->zoom_level, *r);
		mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->img.img_ptr, 0, 0);
	}
	return (0);
}

int			test_args(int ac, char **av, t_mlx *r)
{
	if (ac != 2)
		return (0);
	r->code_f = ft_atoi(av[1]);
	if (r->code_f != 1 && r->code_f != 2 && r->code_f != 3)
		return (0);
	return (1);
}

int			mouse_moove(int x, int y, t_mlx *r)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (0);
	r->fract->zoom_level++;
	r->fract->cr = -0.7 + (double)x / 1000;
	r->fract->ci = 0.27015 + (double)y / 1000;
	fract(r->fract->zoom_level, *r);
	mlx_clear_window(r->mlx_ptr, r->win_ptr);
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->img.img_ptr, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx			r;

	r = create_mlx();
	if (!test_args(ac, av, &r))
	{
		ft_putendl("usage: ./fractol [1:julia, 2:mandelbrot, 3]");
		return (0);
	}
	fract(0, r);
	mlx_put_image_to_window(r.mlx_ptr, r.win_ptr, r.img.img_ptr, 0, 0);
	mlx_hook(r.win_ptr, 6, (1L << 6), mouse_moove, &r);
	mlx_key_hook(r.win_ptr, interrupt, &r);
	mlx_mouse_hook(r.win_ptr, zoom, &r);
	mlx_loop(r.mlx_ptr);
	return (1);
}
