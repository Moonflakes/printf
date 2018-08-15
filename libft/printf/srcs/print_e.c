/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:14:50 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 10:48:25 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*char_e(long double e, int precision, int *exp)
{
	char	*nb;
	int		i;
	int		k;

	i = -1;
	k = e * 1;
	if (!(nb = (char*)ft_memalloc(sizeof(char) * (precision + 3))))
		return (NULL);
	while (++i < precision + 2)
	{
		nb[i] = k + '0';
		e = e - k;
		e = e * 10;
		k = e;
	}
	nb[i] = '\0';
	i =  (nb[0] == 0) ? 1 : 0;
	return (round_d(nb, exp, 0));
}

int		print_e(char c, t_arg *arg, t_flags *flags, int num)
{
	int sign;
	int	exp;
	long double e;
	char *nb;

	e = arg->d[flags->index_arg[num]];
	sign = (e < 0.0) ? 1 : 0;
	e = (sign == 1) ? -e : e;
	exp = (e == 0.0) ? 0 : exposant_d(&e);
	nb = char_e(e, flags->precision[num], &exp);
	nb = (flags->precision[num]) ? add_exp(insert_point_sign(nb, 0, sign, 0), exp, c, 0) : add_exp(nb, exp, c, sign);

	return (printing(&nb, arg, flags, num));
}
