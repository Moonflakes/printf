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

char		*putg(char *nb, long long nblen)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!(str = (char*)ft_memalloc(sizeof(char) * ft_strlen(nb) + 2)))
		return (NULL);
	i = 0;
	j = 0;
	k = nblen;
//	ft_putnbr(k);
//	ft_putendl(" : k");
//	ft_putendl(nb);
	while (nb[i])
	{
		if (i == k)
		{
			str[j] = '.';
			j++;
		}
		str[j] = nb[i];
		i++;
		j++;
	}
	str[j] = '\0';
	ft_strdel(&nb);
//	ft_putendl(str);
	return (str);
}

char		*if_g_neg(long double *g, char *sign_nb)
{
	if (g[0] < 0)
	{
		sign_nb = ft_strdup_del("-", sign_nb);
		g[0] = -g[0];
	}
	return (sign_nb);
}

char		*process_nb(double g, int i, int precision)
{
	char	*nb;
	int		j;

	if (precision == 0)
	{
		j = (g * 10) - (i * 10);
		if (j >= 5)
			i++;
		nb = ft_strjoin_free(ft_itoa(i), ".", 1);
	}
	else
		nb = round_g(ft_strjoin_free(ft_itoa(i), ft_dtoa(((g *
			(ft_power_double(10, precision) /
			ft_iterative_power(10, (ft_nblen(i) - 1)))) -
			(i * (ft_power_double(10, precision) /
			ft_iterative_power(10, (ft_nblen(i) - 1)))))), 0));
	return (nb);
}

/*double		ft_power_g(double e, long long *i, long long *exp)
{
	while (e > 10)
	{
		e = e / 10;
		exp[0]++;
	}
	i[0] = e * 10;
	i[0] = ft_atoi(round_g(ft_itoa(i[0])));
	return (e);
}*/

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

char	*add_zero_g(char *nb, int exp)
{
	char	*g;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	len = ft_strlen(nb) - exp;
	if (!(g = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < len)
	{
		if (i < -exp)
			g[i] = '0';
		else
			g[i] = nb[++j];
	}
	return (g);
}

char	*suppr_zero(char *nb)
{
	int i;

	i = ft_strlen(nb);
	while (nb[--i] == '0')
		nb[i] = '\0';
	if (nb[i] == '.')
		nb[i] = '\0';
	return (nb);
}

char	*insert_point_sign(char *nb, int exp, int sign)
{
	char	*nbb;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(nb) + 1 + sign;
	i = -1;
	j = -1;
	if (!(nbb = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	if (sign)
		nbb[++i] = '-';
	while (++i < len)
	{
		nbb[i] = (i == exp + 1 + sign) ? '.' : nb[++j];
	}
	nbb[i] = '\0';
	ft_strdel(&nb);
	return (suppr_zero(nbb));
}

char	*add_exp(char *nb, int exp, char e)
{
	char	*nbexp;
	char	sign_exp;
	int		len;
	int		i;

	len = ft_strlen(nb) + 3;
	sign_exp = (exp < 0) ? '-': '+';
	exp = abs_value(exp);
	i = -1;
	if (!(nbexp = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (nb[++i])
		nbexp[i] = nb[i];
	nbexp[i] = e;
	nbexp[++i] = sign_exp;
	if (exp < 10)
		nbexp[++i] = '0';
	ft_strdel(&nb);
	nb = ft_strjoin_free(nbexp, ft_itoa(exp), 0);
	return (nb);
}

int			print_g(char c, t_arg *arg, t_flags *flags, int num)
{
	int sign;
	int	exp;
	long double g;
	char *nb;

//	nb = NULL;
	g = arg->d[flags->index_arg[num]];
	sign = (g < 0.0) ? 1 : 0;
	g = (sign == 1) ? -g : g;
	flags->precision[num]  = (flags->precision[num]) ? flags->precision[num] : 1;
	exp = (g == 0.0) ? 0 : exposant_g(&g);
	if (exp < 0 && abs_value(exp) <= 4)
	{
		nb = insert_point_sign(round_g(add_zero_g(char_g(g, flags->precision[num]), exp)), 0, sign);
	}
	else if (exp >= 0 && exp <= flags->precision[num] - 1)
	{
		nb = insert_point_sign(round_g(char_g(g, flags->precision[num])), exp, sign);
	}
	else
	{
		nb = add_exp(insert_point_sign(round_g(char_g(g, flags->precision[num])), 0, sign), exp, c - 2);
	}
	return (printing(&nb, arg, flags, num));
}
/*
int			print_g(char c, t_arg *arg, t_flags *flags, int num)
{
	long double	g;
	char		*nb;
	t_g			*val;
	int			i;

	g = arg->d[flags->index_arg[num]];
	i = g * 1;
//	ft_putnbr(g);
//	ft_putendl(" : g");
	val = init_struct_g(arg, flags, num, c);
	val->sign_nb = if_g_neg(&g, val->sign_nb);
	nb = NULL;
	if (flags->precision[num] == 0 && g - i == 0)
	{
//		ft_putendl("la");
		nb = ft_pr(g, flags, val, nb);
//		ft_putstr(nb);
//		ft_putendl(" : nb 1");
	}
	else if (g > (9 * ft_power_double(10, val->i)) && g < ft_power_double(10,
				flags->precision[num]))
	{
//		ft_putendl("ici");
		nb = ft_strjoin_free(val->sign_nb,
			putg(nb_g(g, &val->exp, flags->precision[num], -val->i),
				ft_nblen(g * 1)), 0);
//		ft_putendl("la");
//		ft_putstr(nb);
//		ft_putendl(" : nb 2");
	}
	else
	{
//		ft_putendl("ou la");
		val->i = 0;
		val->exp = 1;
		g = ft_power(g, &val->i, &val->exp);
		nb = (g == 0) ? ft_strdup_del("0", val->sign_nb) : ft_strjoin_free(val->sign_nb, pute(suppr_zero(process_nb(g, val->i,
			flags->precision[num])), val->c, val->exp - 1, val->i), 0);
//		ft_putendl("ici");
//		ft_putstr(nb);
//		ft_putendl(" : nb 3");
	}
	free_t_g(val);
	return (printing(&nb, arg, flags, num));
}
*/