/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:16:53 by mthiery           #+#    #+#             */
/*   Updated: 2018/03/01 11:16:55 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_doublen(long double nb)
{
	int i;

	i = nb < 1 ? 1 : 0;
	while (nb > 1)
	{
		nb /= 10;
		++i;
	}
	return (i);
}

int		start_d(long double n, char **nb)
{
	int			i;
	int			u;
	long double	a;

	a = 10;
	i = 0;
	u = -1;
	while (n / a > 1)
	{
		a *= 10;
		++i;
	}
	a /= 10;
	while (a >= 1)
	{
		(*nb)[++u] = (n / a) + '0';
		n -= (int)(n / a) * a;
		a /= 10;
	}
	return (i);
}

void	end_d(long double *d, int precision, int *i, char **nb)
{
	int j;

	j = 0;
	while (++j < precision)
	{
		(*d) *= 10;
		(*nb)[++(*i)] = (int)(*d) + '0';
		(*d) -= (int)(*d);
	}
}