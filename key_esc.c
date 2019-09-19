/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_esc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 06:22:06 by czhang            #+#    #+#             */
/*   Updated: 2019/09/04 18:13:47 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	interrupt(int key, void *p)
{
	t_mlx	*r;

	r = (t_mlx *)p;
	if (key == 53)
	{
		mlx_destroy_image(r->mlx_ptr, r->img.img_ptr);
		mlx_destroy_window(r->mlx_ptr, r->win_ptr);
		exit(EXIT_SUCCESS);
	}
	(void)p;
	return (0);
}
