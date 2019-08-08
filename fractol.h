/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 02:46:42 by czhang            #+#    #+#             */
/*   Updated: 2019/07/23 02:01:15 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <complex.h>
# include <fcntl.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 200

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

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_tab
{
	void	**data;
	int		x_size;
	int		y_size;
}				t_tab;

int				read_file(t_tab *tab, char *filename);
void			ptit_free(t_tab *tab);
t_tab			*new_tab(int x_size, int y_size);
int				substract_t_coord(t_tab *tab, t_coord min);
int				divide_t_coord(t_tab *tab, double value);
int				tab_coord(t_tab *tab_iso, t_tab *tab_int, double angle[2]);
int				draw(t_tab *tab, t_mlx r);
int				interrupt(int key, void *p);
t_coord			*update_range(t_tab *iso);
int				resize_coord(t_tab *iso, t_coord range[2]);

#endif
