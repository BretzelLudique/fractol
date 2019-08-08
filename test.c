#include "fractol.h"

int	test_mandel(int ac, char av)
{
	double complex	z;
	double complex	c;
	int		i;

	if (ac != 5)
		ft_putendl_fd("please put 2 args for a mandelbrot");
	z = ft_atoi(av[1]) + ft_atoi(av[2]) * I;
	c = ft_atoi(av[3]) + ft_atoi(av[4]) * I;
	i = -1;
	while (++i < MAX_ITER)
	{
		z = z * z + c 
	}
}
