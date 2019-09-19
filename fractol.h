	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   fractol.h                                          :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2019/07/05 04:44:18 by czhang            #+#    #+#             */
/*   Updated: 2019/09/19 05:47:51 by czhang           ###   ########.fr       */
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

typedef struct	s_img
{
	void	*img_ptr;
	char	*img_str;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

int	draw(double complex c, t_mlx r);
int	interrupt(int key, void *p);
void	printz(double complex z);

#endif
