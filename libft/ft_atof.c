/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:25:51 by czhang            #+#    #+#             */
/*   Updated: 2019/09/09 20:57:24 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int			i;
	int			sign;
	int			dec_n;
	long double	answer;

	answer = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
		answer = 10 * answer + str[i++] - '0';
	if ((dec_n = 0) == 0 && str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		answer = 10 * answer + str[i++] - '0';
		dec_n++;
	}
	while (dec_n--)
		answer /= 10;
	return ((double)answer * sign);
}
