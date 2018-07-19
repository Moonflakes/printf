/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:40:01 by mthiery           #+#    #+#             */
/*   Updated: 2018/03/09 11:40:05 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*nb_zero(int i)
{
	char *nb;

	nb = ft_memalloc(i);
	while (i > 0)
	{
		nb[i - 1] = '0';
		i--;
	}
	return (nb);
}

char	*suppr_zero(char *nb)
{
	int i;

	i = ft_strlen(nb) - 1;
	while (nb[i] == '0')
	{
		nb[i] = '\0';
		i--;
	}
	return (nb);
}

char	*suppr_zero_b(char *nb, long long *exp)
{
	int i;

	i = ft_strlen(nb) - 1;
	while (nb[i] == '0')
	{
		nb[i] = '\0';
		i--;
	}
	exp[0] = ft_strlen(nb) - i;
	return (nb);
}

char	*nb_g(double g, long long *exp, int precision, long long i)
{
	char *nb;

	nb = NULL;
	if (g >= 1)
	{
//		ft_putendl("lala");
		while (g < ft_power_double(10, precision))
		{
			g = g * 10;
			exp[0]++;
		}
		nb = suppr_zero(round_g(ft_dtoa(g)));
	}
	if (g > 0 && g < 1)
	{
//		ft_putendl("lulu");
		while (g < 1)
		{
			g = g * 10;
			exp[0]++;
		}
//		ft_putnbr(g);
//		ft_putendl(" : g");
		nb = ft_strjoin_free(nb_zero(exp[0]),
			suppr_zero(round_g(ft_dtoa(g * ft_iterative_power_double(10, i)))), 0);
	}
	if (g == 0)
	{
//		ft_putendl("lolo");
		nb = ft_strdup("0");
	}
	return (nb);
}
