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

#include "printf.h"

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

int		dble_process(long double *d, int length)
{
	int		exp;
	double	i;

	exp = (length && d[0] != 0) ? -4 : 0;
	if (d[0] >= 1)
	{
		i = (length) ? 1 : 2;
		while (d[0] >= i)
		{
			d[0] = d[0] / 2;
			++exp;
		}
	}
	else if (d[0] < 1 && d[0] != 0)
	{
		i = (length) ? 0.5 : 1;
		while (d[0] < i)
		{
			d[0] = d[0] * 2;
			--exp;
		}
	}
	return (exp);
}

char	*insert_x_point(char *str, int pr)
{
	char	*hex;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str) + 3;
	i = -1;
	j = -1;
	if (!(hex = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	hex[++i] = '0';
	hex[++i] = 'x';
	while (++i < len)
		hex[i] = (i == 3) ? '.' : str[++j];
	hex[i] = '\0';
	ft_strdel(&str);
	return (pr) ? hex : suppr_zero(hex);
}

char	*convert_hex(long double d, int precision, int length)
{
	int		i;
	int		j;
	char	*hex;

	if (!(hex = (char*)ft_memalloc(sizeof(char) * (precision + 2))))
		return (NULL);
	i = -1;
	j = d;
	if (!length)
		hex[++i] = (j > 9) ? 'a' + j - 10 : j + '0';
	while (++i <= precision + 1)
	{
		d = d * 16;
		j = d;
		d = d - j;
		if (i == 1 && j && !length)
			j = j - 16;
		hex[i] = (j > 9) ? 'a' + j - 10 : j + '0';
	}
	hex[i] = '\0';
	return (round_hex(hex));
}


int		print_a(char a, t_arg *arg, t_flags *flags, int num)
{
	long double	d;
	int			exp;
	int			sign_pr[2];
	char		*hex;
	int			u;

	d = arg->d[flags->index_arg[num]];
	u = *(((size_t *)&arg->d[flags->index_arg[num]]) + 1);
	sign_pr[0] = ((d == 0 && u != 0) || d < 0) ? 1 : 0;
	sign_pr[1] = ((arg->precision[num] && !flags->precision[num]) || !arg->precision[num]) ? 0 : 1;
	d = (sign_pr[0]) ? -d : d;
	exp = dble_process(&d, arg->length[num]);
	hex = convert_hex(d, flags->precision[num], arg->length[num]);
	hex = if_maj(add_exp(insert_x_point(hex, sign_pr[1]), exp, 'p', sign_pr[0]), a);

/*
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
	hex = convert_hex(d, flags->precision[num]);
	hex = dtoa_base(d, &sign, exp, flags->precision[num] + 1);
//	ft_putendl("");
//	ft_putstr(hex);
//	ft_putendl(" : hex");*/
	return (printing(&hex, arg, flags, num));
}
