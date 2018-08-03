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

char	*process_exp(int exp, int nbb)
{
	char *exposant;
	char *sign_exp;

	sign_exp = ft_strdup("+");
	if (exp == 0)
		exp = ft_nblen(nbb) - 1;
	if (exp < 0)
	{
		sign_exp = ft_strdup_del("-", sign_exp);
		exp = -exp;
	}
	if (exp < 10)
		exposant = ft_strjoin_free("0", ft_itoa(exp), 2);
	else
		exposant = ft_itoa(exp);
	exposant = ft_strjoin_free(sign_exp, exposant, 0);
	return (exposant);
}

char	*pute(char *nb, char e, int exp, int nbb)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
//	ft_putendl(nb);
	if (!(str = (char*)ft_memalloc(sizeof(char) * 11)))
		return (NULL);
	while (str[i] || nb[j])
	{
		if (i == 1)
			str[i++] = '.';
		if (nb[j] != '.')
			str[i++] = nb[j];
		j++;
	}
	str[i] = e;
	str[++i] = '\0';
//	ft_putendl(str);
	ft_strdel(&nb);
	str = ft_strjoin_free(str, process_exp(exp, nbb), 0);
	return (str);
}

long double	ft_power(long double e, long long *i, long long *exp)
{
	if (e < 1 && e > 0)
	{
		while (e < 1)
		{
			e = e * 10;
			exp[0]++;
		}
		exp[0] = -exp[0] + 2;
	}
	if (e >= 1)
	{
		while (e > 10)
		{
			e = e / 10;
			exp[0]++;
		}
	}
	i[0] = e;
	return (e);
}

char	*ft_zero_e(int precision)
{
	char *zero;
	int i;

	i = 0;
	if (!(zero = (char*)ft_memalloc(sizeof(char) * precision + 1)))
		return (NULL);
	while (precision >= i)
	{
		zero[i] = '0';
		i++;
	}
	zero[i] = '\0';
//	ft_putendl(zero);
	return (zero);
}

char *dtoa_rest(long long rest, int precision)
{
	int nb_zero;
	char *rest_nb;

	nb_zero = ft_nblen(rest) - precision + 1;
//	ft_putnbr(rest);
//	ft_putendl(" : rest");
//	ft_putnbr(precision);
//	ft_putendl(" : precision");
	if (nb_zero != 0)
		rest_nb = ft_dtoa(rest);
	else
		rest_nb = ft_strjoin_free(ft_zero_e(nb_zero + 1), ft_dtoa(rest), 0);
	return (rest_nb);
}

int		print_e(char c, t_arg *arg, t_flags *flags, int num)
{
	long double	e;
	char		*nb;
	char		*sign_nb;
	long long	i[3];
	long long	exp;

	e = arg->d[flags->index_arg[num]];
//	ft_putnbr(e * 100);
//	ft_putendl(" : e1");
	i[0] = 0;
	exp = 1;
	sign_nb = ft_strdup("");
	if (e < 0)
	{
		e = -e;
		sign_nb = ft_strdup_del("-", sign_nb);
	}
	i[1] = (e < 1) ? 1 : 0;
	e = ft_power(e, i, &exp);
//	ft_putnbr(e * 100);
//	ft_putendl(" : e");
//	ft_putnbr(i[0]);
//	ft_putendl(" : i[0]");
//	ft_putnbr(flags->precision[num]);
//	ft_putendl(" : flags->precision[num]");
	i[2] = (e * (ft_power_double(10,
			flags->precision[num] + 1) / ft_iterative_power(10,
			(ft_nblen(i[0]) - 1)))) - (i[0] * (ft_power_double(10,
			flags->precision[num] + 1) / ft_iterative_power(10,
			(ft_nblen(i[0]) - 1))));		
	if (e - i[0] == 0)
		nb = ft_strjoin_free(sign_nb, pute(round_e(i[1],
		ft_strjoin_free(ft_itoa(i[0]), ft_zero_e(flags->precision[num]), 0)), c, exp - 1, i[0]), 0);
	else
		nb = ft_strjoin_free(sign_nb, pute(round_e(i[1],
			ft_strjoin_free(ft_itoa(i[0]), dtoa_rest(i[2], flags->precision[num]), 0)), c, exp - 1, i[0]), 0);
//	ft_putendl(nb);
	return (printing(&nb, arg, flags, num));
}
