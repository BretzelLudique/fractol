/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_ft_putnbrf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 06:35:53 by czhang            #+#    #+#             */
/*   Updated: 2019/09/19 07:56:03 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bad_ft_putnbrf(float n)
{
	double	dec_part;
	int		i;

	ft_putnbr(n);
	dec_part = n - (int)n;
	i = 0;
	while (i++ < 5)
		dec_part *= 10;
	ft_putchar('.');
	i = 10;
	while (dec_part % i)
	ft_putnbr(dec_part);
}
