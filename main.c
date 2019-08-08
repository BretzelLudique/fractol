/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 02:51:07 by czhang            #+#    #+#             */
/*   Updated: 2019/07/23 02:19:51 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

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

static int		reterr(char const *s, t_tab *tab, t_tab *tab2)
{
	ptit_free(tab);
	ptit_free(tab2);
	if (s)
		ft_putendl_fd(s, 2);
	return (0);
}

int				test_arg(int ac, char **av)
{
	if (ac != 2 && ac != 4)
	{
		ft_putendl_fd("Usage : ./fdf <filename> [angle alpha, angle omega]", 2);
		return (0);
	}
	if (ac == 4 && ft_atoi(av[2]) == 0 && ft_atoi(av[3]) == 0)
		ft_putendl_fd("warning : both angles are set to 0", 2);
	return (1);
}

int				main(int ac, char **av)
{
	t_mlx	r;
	t_tab	*tab;
	t_tab	*iso;

/*	if (!test_arg(ac, av))
		return (0);
	if (!(tab = new_tab(0, 0)) || !(read_file(tab, av[1])))
		return (reterr(0, tab, 0));
	if (!(iso = new_tab(tab->x_size, tab->y_size))
			|| !tab_coord(iso, tab, angle))
		return (reterr("tab_iso", tab, iso));
*/
	r = create_mlx();
	resize_coord(iso, update_range(iso));
	draw(iso, r);
	mlx_put_image_to_window(r.mlx_ptr, r.win_ptr, r.img.img_ptr, 0, 0);
	mlx_key_hook(r.win_ptr, interrupt, &r);
	mlx_loop(r.mlx_ptr);
//	ptit_free(tab);
//	ptit_free(iso);
	return (0);
}

