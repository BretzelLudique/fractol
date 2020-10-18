/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 18:06:36 by czhang            #+#    #+#             */
/*   Updated: 2019/11/02 19:26:52 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct	s_fract
{
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
	int			iter_max;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_x;
	double		zoom_y;
	int			mod;
}				t_fract;

typedef struct	s_img
{
	void		*img_ptr;
	char		*img_str;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef	struct	s_mlx
{
	int			code_f;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_fract		*fract;
}				t_mlx;

int				fract(int mod, t_mlx r);
int				draw_pixel(int x, int y, int blue, t_mlx r);
int				key_events(int key, t_mlx *r);

#endif
