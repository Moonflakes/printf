/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 09:46:09 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:34:25 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*if_nbneg(char *str, int exp, char *signe, t_sign *sign)
{
	if (sign->nb)
		str = ft_strjoin_free(ft_strjoin_free(if_maj("-0x", sign->a), str, 2),
			ft_strjoin_free(signe, ft_itoa(exp), 2), 0);
	else
		str = ft_strjoin_free(ft_strjoin_free(if_maj("0x", sign->a), str, 2),
			ft_strjoin_free(signe, ft_itoa(exp), 2), 0);
	return (str);
}

int		ldble_process(long double *d, int *exp)
{
	if (d[0] == 0)
		return (0);
	if (d[0] >= 1)
	{
		while (d[0] >= 1)
		{
			d[0] = d[0] / 2;
			exp[0]++;
		}
	}
	else
	{
		while (d[0] < 0.5)
		{
			d[0] = d[0] * 2;
			exp[0]--;
		}
	}
	exp[0] = exp[0] - 4;
	return (exp[0] < 0) ? 1 : 0;
}

int		print_la(char a, t_arg *arg, t_flags *flags, int num)
{
	long double	d;
	int			exp;
	t_sign		*sign;
	char		*hex;

	d = arg->d[flags->index_arg[num]];
	sign = init_struct_sign(a, arg, num);
	exp = 0;
	sign->ld = 1;
	if (d < 0)
	{
		d = -d;
		sign->nb = 1;
	}
	sign->exp = ldble_process(&d, &exp);
	hex = dtoa_base(d, sign, exp, flags->precision[num] + 1);
	free_t_sign(sign);
	return (printing(&hex, arg, flags, num));
}
