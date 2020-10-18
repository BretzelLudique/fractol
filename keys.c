/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_esc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 06:22:06 by czhang            #+#    #+#             */
/*   Updated: 2019/11/02 18:26:08 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	move_x(int key, t_mlx *r)
{
	double	dx;

	dx = (r->fract->x2 - r->fract->x1) / 5;
	if (key == 123)
	{
		r->fract->x1 -= dx;
		r->fract->x2 -= dx;
	}
	if (key == 124)
	{
		r->fract->x1 += dx;
		r->fract->x2 += dx;
	}
	return (0);
}

static int	move_y(int key, t_mlx *r)
{
	double	dy;

	dy = (r->fract->y2 - r->fract->y1) / 5;
	if (key == 125)
	{
		r->fract->y1 += dy;
		r->fract->y2 += dy;
	}
	if (key == 126)
	{
		r->fract->y1 -= dy;
		r->fract->y2 -= dy;
	}
	return (0);
}

static int	key_move(int key, t_mlx *r)
{
	if (key == 123 || key == 124)
		move_x(key, r);
	else if (key == 125 || key == 126)
		move_y(key, r);
	r->fract->mod = 1;
	fract(r->fract->mod, *r);
	mlx_clear_window(r->mlx_ptr, r->win_ptr);
	mlx_put_image_to_window(r->mlx_ptr, r->win_ptr, r->img.img_ptr, 0, 0);
	return (0);
}

int			key_events(int key, t_mlx *r)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
		key_move(key, r);
	if (key == 53)
	{
		mlx_destroy_image(r->mlx_ptr, r->img.img_ptr);
		mlx_destroy_window(r->mlx_ptr, r->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
