/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 10:54:30 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 10:11:13 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	roundf_hex(char *str, int i, t_sign *sign)
{
	while (str[i] == 'f')
	{
		str[i] = (sign->pr_z == 1) ? '1' : '0';
		sign->rnd = (sign->pr_z == 1) ? 4 : 0;
		i--;
	}
	if (str[i] == '.')
	{
		if (str[i - 1] != 'f')
			i--;
		else if (sign->ld == 1)
		{
			str[i - 1] = '1';
			sign->rnd = 4;
			return ;
		}
		if (str[i - 1] == '1' && sign->ld == 0)
			str[i - 1] = str[i - 1] + 1;
	}
	str[i] = (str[i] != '9') ? str[i] + 1 : 'a';
}

void	ft_round_hex(double d, t_sign *sign, char *str)
{
	int i;

	i = 0;
	d = (sign->pr_z == 1) ? sign->j : d * 16;
//	ft_putnbr(d);
//	ft_putendl(" : d");
//	ft_putendl(str);
	if (d == 16 && str[i] == '0')
		str[i] = '0';
	else if (d > 8 && str[i] != '9' && str[i] != 'f')
		str[i] = str[i] + 1;
	else if (d > 8 && str[i] == '9')
		str[i] = 'a';
	else if (d > 8 && str[i] == 'f')
		roundf_hex(str, i, sign);
//	ft_putendl(str);
}

char	*if_maj(char *str, char a)
{
	int i;

	i = 0;
	if (a == 'A' || a == 'X')
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (str);
}

int		dble_process(long double *d, int *exp)
{
	if (d[0] == 0)
		return (0);
	if (d[0] >= 1)
	{
		while (d[0] >= 2)
		{
			d[0] = d[0] / 2;
			exp[0]++;
		}
	}
	else
	{
		while (d[0] < 1)
		{
			d[0] = d[0] * 2;
			exp[0]--;
		}
		return (1);
	}
	return (0);
}

int		print_a(char a, t_arg *arg, t_flags *flags, int num)
{
	long double	d;
	int			exp;
	t_sign		sign;
	char		*hex;

	d = arg->d[flags->index_arg[num]];
	ft_bzero(&sign, sizeof(t_sign));
	sign.a = a;
	sign.pr = arg->precision[num];
	exp = 0;
	if (d < 0)
	{
		d = -d;
		sign.nb = 1;
	}
	sign.exp = dble_process(&d, &exp);
	hex = dtoa_base(d, &sign, exp, flags->precision[num] + 1);
	return (printing(&hex, arg, flags, num));
}
