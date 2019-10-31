	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   fractol.h                                          :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2019/07/05 04:44:18 by czhang            #+#    #+#             */
/*   Updated: 2019/10/31 18:19:14 by czhang           ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H


# include <stdio.h> //A SUPPRIMERRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR



# include <complex.h>
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct	s_mandel
{
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
	int			i;
	int			iter_max;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_x;
	double		zoom_y;
	int			zoom_level;
}				t_mandel;

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
	t_mandel	*fract;
}				t_mlx;

int	fract(int zoom_level, t_mlx r);
int	draw_pixel(int x, int y, int blue, t_mlx r);
int	interrupt(int key, void *p);
int	zoom(int key, int x, int y, t_mlx *r);

#endif
