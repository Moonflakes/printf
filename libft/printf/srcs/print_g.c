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

int		abs_value(int value)
{
	value = value < 0 ? -value : value;
	return (value);
}

char	*char_g(long double g, int precision, int *exp)
{
	char	*nb;
	int		i[2];

	i[0] = -1;
	i[1] = g * 1;
	if (!(nb = (char*)ft_memalloc(sizeof(char) * (precision + 2))))
		return (NULL);
	while (++i[0] < precision + 1)
	{
		nb[i[0]] = i[1] + '0';
		g = g - i[1];
		g = g * 10;
		i[1] = g;
	}
	nb[i[0]] = '\0';
	i[0] = 0;
	i[1] = 'g';
	return (*exp < 0 && abs_value(*exp) <= 4) ? add_zero_d(nb, exp, i) :
												round_d(nb, exp, 1);
}

int		print_g(char c, t_arg *arg, t_flags *flags, int num)
{
	int			sign_point[2];
	int			exp;
	long double	g;
	char		*nb;
	int			u;

	g = arg->d[flags->index_arg[num]];
	u = *(((size_t *)&arg->d[flags->index_arg[num]]) + 1);
	sign_point[0] = ((g == 0 && u != 0) || g < 0) ? 1 : 0;
	sign_point[1] = 0;
	g = (sign_point[0]) ? -g : g;
	flags->precision[num] = (flags->precision[num]) ? flags->precision[num] : 1;
	exp = (g == 0.0) ? 0 : exposant_d(g);
	nb = char_g(g, flags->precision[num], &exp);
	if ((exp < 0 && abs_value(exp) <= 4) ||
		(exp >= 0 && exp <= flags->precision[num] - 1))
		nb = insert_point_sign(nb, exp, sign_point, 1);
	else
		nb = add_exp(insert_point_sign(nb, 0, sign_point, 1), exp, c - 2, 0);
	return (printing(&nb, arg, flags, num));
}