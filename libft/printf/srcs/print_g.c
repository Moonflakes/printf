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

#include "../includes/printf.h"

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
	if (i == 1)
	{
		str[j] = '.';
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
		nb = (g == 1) ? ft_strdup_del("1", val->sign_nb) : ft_strjoin_free(val->sign_nb,
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
