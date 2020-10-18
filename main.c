/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 04:44:02 by czhang            #+#    #+#             */
/*   Updated: 2019/11/02 19:20:30 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_mlx	create_mlx(void)
{
	t_mlx		r;
	t_fract		*f;

	r.mlx_ptr = mlx_init();
	r.win_ptr = mlx_new_window(r.mlx_ptr, WIDTH, HEIGHT, "fractol");
	r.img.img_ptr = mlx_new_image(r.mlx_ptr, WIDTH, HEIGHT);
	r.img.img_str = mlx_get_data_addr(r.img.img_ptr,
			&r.img.bpp, &r.img.size_line, &r.img.endian);
	r.fract = (t_fract *)malloc(sizeof(t_fract));
	return (r);
}

static int		zoom(int key, int x, int y, t_mlx *r)
{
	double		posx;
	double		posy;

	if (key != 4 && key != 5)
		return (0);
	posx = r->fract->x1 + x * (r->fract->x2 - r->fract->x1) / WIDTH;
	posy = r->fract->y1 + y * (r->fract->y2 - r->fract->y1) / HEIGHT;
	r->fract->mod++;
	if (key == 4)
	{
		r->fract->x1 = posx - (r->fract->x2 - r->fract->x1) / 4;
		r->fract->x2 = posx + (r->fract->x2 - r->fract->x1) / 4;
		r->fract->y1 = posy - (r->fract->y2 - r->fract->y1) / 4;
		r->fract->y2 = posy + (r->fract->y2 - r->fract->y1) / 4;
	}
	else if (key == 5)
	{
		r->fract->x1 = posx - (r->fract->x2 - r->fract->x1);
		r->fract->x2 = posx + (r->fract->x2 - r->fract->x1);
		r->fract->y1 = posy - (r->fract->y2 - r->fract->y1);
		r->fract->y2 = posy + (r->fract->y2 - r->fract->y1);
	}
	fract(r->fract->mod, *r);
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->img.img_ptr, 0, 0);
	return (0);
}

static int		test_args(int ac, char **av, t_mlx *r)
{
	if (ac != 2)
		return (0);
	r->code_f = ft_atoi(av[1]);
	if (r->code_f != 1 && r->code_f != 2 && r->code_f != 3)
		return (0);
	return (1);
}

static int		mouse_moove(int x, int y, t_mlx *r)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (0);
	r->fract->mod++;
	r->fract->cr = -0.7 + (double)x / 1000;
	r->fract->ci = 0.27015 + (double)y / 1000;
	fract(r->fract->mod, *r);
	mlx_clear_window(r->mlx_ptr, r->win_ptr);
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->img.img_ptr, 0, 0);
	return (0);
}

int				main(int ac, char **av)
{
	t_mlx			r;

	r = create_mlx();
	if (!test_args(ac, av, &r))
	{
		ft_putendl("usage: ./fractol [1:julia, 2:mandelbrot, 3:tricorn]");
		return (0);
	}
	fract(0, r);
	mlx_put_image_to_window(r.mlx_ptr, r.win_ptr, r.img.img_ptr, 0, 0);
	if (r.code_f == 1)
		mlx_hook(r.win_ptr, 6, (1L << 6), mouse_moove, &r);
	mlx_key_hook(r.win_ptr, key_events, &r);
	mlx_mouse_hook(r.win_ptr, zoom, &r);
	mlx_loop(r.mlx_ptr);
	return (1);
}
