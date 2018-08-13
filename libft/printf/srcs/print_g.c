/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:03:05 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:29:47 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		exposant_g(long double *g)
{
	int	exp;
	
	exp = 0;
	if (g[0] < 1)
	{
		while (g[0] < 1)
		{
			g[0] = g[0] * 10;
			--exp;
		}
	}
	else
	{
		while (g[0] / 10 > 1)
		{
			g[0] = g[0] / 10;
			++exp;
		}
	}
	return (exp);
}

int		abs_value(int value)
{
	value = value < 0 ? -value : value;
	return (value);
}

char	*char_g(long double g, int precision)
{
	char	*nb;
	int		i;
	int		k;

	i = -1;
	k = g * 1;
	if (!(nb = (char*)ft_memalloc(sizeof(char) * (precision + 2))))
		return (NULL);
	while (++i < precision + 1)
	{
		nb[i] = k + '0';
		g = g - k;
		g = g * 10;
		k = g;
	}
	nb[i] = '\0';
	return (nb);
}

int			print_g(char c, t_arg *arg, t_flags *flags, int num)
{
	int sign;
	int	exp;
	long double g;
	char *nb;

	g = arg->d[flags->index_arg[num]];
	sign = (g < 0.0) ? 1 : 0;
	g = (sign == 1) ? -g : g;
	flags->precision[num]  = (flags->precision[num]) ? flags->precision[num] : 1;
	exp = (g == 0.0) ? 0 : exposant_g(&g);
	if (exp < 0 && abs_value(exp) <= 4)
		nb = insert_point_sign(round_g(add_zero_g(char_g(g, flags->precision[num]), exp)), 0, sign);
	else if (exp >= 0 && exp <= flags->precision[num] - 1)
		nb = insert_point_sign(round_g(char_g(g, flags->precision[num])), exp, sign);
	else
		nb = add_exp(insert_point_sign(round_g(char_g(g, flags->precision[num])), 0, sign), exp, c - 2);
	return (printing(&nb, arg, flags, num));
}