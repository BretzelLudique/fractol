/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 04:44:02 by czhang            #+#    #+#             */
/*   Updated: 2019/10/30 22:04:23 by czhang           ###   ########.fr       */
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

int	zoom(int key, int x, int y, void *p)
{
	t_mlx		*r;
	double		dx;
	double		dy;

	r = (t_mlx *)p;
	if (key == 1)
	{
		*(r->fract.zoom_level) = 1;
		dx = (r->fract.x2 - r->fract.x1) / 4;
		ft_putnbrb("100x1", 100 * *(r->fract.x1));
		dy = (r->fract.y2 - r->fract.y1) / 4;
		*(r->fract.x1) = x + dx;
		*(r->fract.x2) = x - dx;
		*(r->fract.y1) = y + dy;
		*(r->fract.y2) = y - dy;
		mlx_destroy_image(r->mlx_ptr, r->img.img_ptr);
		r->img.img_ptr = mlx_new_image(r->mlx_ptr, WIDTH, HEIGHT);
		r->img.img_str = mlx_get_data_addr(r->img.img_ptr,
			&r->img.bpp, &r->img.size_line, &r->img.endian);
		fract(r->fract.zoom_level, *r);
		mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->img.img_ptr, 0, 0);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx			r;

	if (ac != 2 || ft_strcmp(av[1], "1"))
		return (0);
	r = create_mlx();
	fract(0, r);
	mlx_put_image_to_window(r.mlx_ptr, r.win_ptr, r.img.img_ptr, 0, 0);
	mlx_key_hook(r.win_ptr, interrupt, &r);
	mlx_mouse_hook(r.win_ptr, zoom, &r);
	mlx_loop(r.mlx_ptr);
	return (1);
}
