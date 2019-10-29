/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:59:29 by czhang            #+#    #+#             */
/*   Updated: 2019/10/29 20:17:53 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_pixel(int x, int y, int blue, t_mlx r)
{
	int		*i;

	i = (int *)(r.img.img_str + 4 * x + r.img.size_line * y);
	if (blue == -1)
		*i = 0;
	else
		*i = blue;
	return (1);
}
