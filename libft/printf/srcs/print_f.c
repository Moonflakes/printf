/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:16:53 by mthiery           #+#    #+#             */
/*   Updated: 2018/03/01 11:16:55 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*char_f(long double f, int precision, int *exp)
{
	char	*nb;
	int		i[2];
	int		len;

	i[0] = -1;
	i[1] = f * 1;
	len = (precision + 2 < 1 - *exp) ? precision + 2 : *exp +  1 + precision + 2;
	if (!(nb = (char*)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	while (++i[0] < len - 1)
	{
		nb[i[0]] = i[1] + '0';
		f = f - i[1];
		f = f * 10;
		i[1] = f;
	}
	nb[i[0]] = '\0';
	i[0] = precision;
	i[1] = 'f';
	return (*exp < 0) ? add_zero_d(nb, exp, i) : round_d(nb, exp, 1);
}

int		print_f(t_arg *arg, t_flags *flags, int num)
{
	int			sign_point[2];
	int			exp;
	long double	f;
	char		*nb;

	f = arg->d[flags->index_arg[num]];
	sign_point[0] = (f < 0.0) ? 1 : 0;
	sign_point[1] = (flags->precision[num] == 0) ? 1 : 0;
	f = (sign_point[0] == 1) ? -f : f;
	exp = (f == 0.0) ? 0 : exposant_d(&f);
	nb = char_f(f, flags->precision[num], &exp);
	nb = insert_point_sign(nb, exp, sign_point, 0);
	return (printing(&nb, arg, flags, num));
}
