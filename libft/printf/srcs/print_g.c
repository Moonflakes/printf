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

int		suppr_zero_g(char **nb)
{
	int i;

	i = ft_strlen(*nb);
	while (--i > 0 && (*nb)[i] == '0')
		(*nb)[i] = '\0';
	if (i > 0 && (*nb)[i] == '.')
		(*nb)[i] = '\0';
	return (i);
}

void	convert_sc(long double *d, int precision, int *i, char **nb)
{
	int j;
	double a;

	j = 0;
	a = 10;
	while (((*d) / a > 1 && (*d) > 1) || ((*d) / a < 1 && (*d) < 1)){
		a = ((*d) < 1) ? a / 10 : a * 10;
	}
	a = ((*d) < 1) ? a : a / 10;
	(*nb)[++(*i)] = ((*d) / a) + '0';
	(*d) = ((*d) / a) - (int)((*d) / a);
	while (++j < precision - 1)
	{
		(*d) *= 10;
		(*nb)[++(*i)] = (int)(*d) + '0';
		(*d) -= (int)(*d);
	}
}

void	start_g(long double d, int *precision, int *i, char **nb)
{
	int u;
	long double a;
	
	a = 10;
	u = -1;
	while (d / a > 1)
	{
		a *= 10;
		++(*i);
	}
	a /= 10;
	while (a >= 1 && (*precision) > 0)
	{
		d > 1 ? --(*precision) : ++(*precision);
		(*nb)[++u] = (d / a) + '0';
		d -= (int)(d / a) * a;
		a /= 10;
	}
	// ft_putendl("");
	// ft_putnbr(*precision);
	// ft_putendl(" : precision");
}

void	end_g(long double *d, int precision, int *i, char **nb)
{
	int j;

	j = 0;
	++(*i);
	while (++j < precision + 1)
	{
		(*d) *= 10;
		(*nb)[++(*i)] = (int)(*d) + '0';
		(*d) -= (int)(*d);
	}
}

int		round_dbl_g(long double d, char **nb, int *len, int precision)
{
	int a;
	int	i;

	a = 0;
	i = ft_strlen(*nb) - 1;
	// ft_putendl("");
	// ft_putnbr(i);
	// ft_putendl(" : i");
	// ft_putnbr(len[1]);
	// ft_putendl(" : len[1]");
	if ((int)((d - (int)d) * 10) >= 8 && (int)d == 9)
	{
		(*nb)[++i] = '0';
		a = reset_nb(nb, i, precision, len[0]);
	}
	else
	{
		if (precision && i + 1 < len[1])
		{
			d += d * 10 - ((int)d * 10) >= 5 ? 1 : 0;
			(*nb)[++i] = (int)d + '0';
		}
		else
		{
			if (i == len[1]) // si le nb est neg
			{
				d += d * 10 - ((int)d * 10) >= 5 ? 1 : 0;
				if ((int)d >= 5)
				{
					while ((*nb)[i] == '9' && i > 0)
					{
						(*nb)[i] = '\0';
						--i;
					}
					(*nb)[i] = (*nb)[i] + 1;
				}
			}
			else if ((*nb)[i] >= '5')
			{
				if ((*nb)[0] == '0' && i - 1 == len[1])
				{
					(*nb)[i] = '\0';
					--i;
				}
				while ((*nb)[i] == '9' && i > 0)
					{
						(*nb)[i] = '\0';
						--i;
					}
					if (i + 1 != len[1])
						(*nb)[i] = (*nb)[i] + 1;
			}
		}
	}
	return (a);
}

char	*char_g_bis(long double d, int precision, int *sign_point, int *exp)
{
	int			i;
	int			k;
	int			len[2];
	char		*nb;

	len[0] = sign_point[0] + sign_point[1] + precision + 1;
	len[1] = precision - sign_point[0];
	i = -1;
	if (!(nb = (char*)ft_memalloc(sizeof(char) * (len[0] + 1))))
		return (NULL);
	start_g(d, &precision, &i, &nb);
	d -= (uint64_t)d;
	k = *exp < 0 ? precision - *exp : precision;
	end_g(&d, k, &i, &nb);
	// ft_putendl("");
	// ft_putstr(nb);
	// ft_putendl(" : nb");
	i = suppr_zero_g(&nb);
	sign_point[1] = i ? 1 : 0;
	d *= 10;
	if ((nb[i] >= '5' && i))
		*exp = *exp + round_dbl_g(d, &nb, len, precision);
	else if (i) {
		if (sign_point[0] && nb[0] == '0') nb[i - 1] = '\0';
		else nb[i] = '\0';
	}
	k = (*exp < 0) ? 1 : *exp + 1;
	insert_point_sign_d(k, &nb, sign_point);
	return (nb);
}

char	*char_sc(long double d, int precision, int *sign_point, int *exp)
{
	int			i;
	int			len;
	int			len_exp;
	char		*nb;

	len_exp = abs_value(*exp) < 10 ? ft_nblen(*exp) + 1 : ft_nblen(*exp);
	len = 1 + sign_point[0] + sign_point[1] + precision + len_exp;
	i = -1;
	if (!(nb = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	convert_sc(&d,  precision, &i, &nb);
	d *= 10;
	if ((int)((d - (int)d) * 10) >= 5)
		*exp = *exp + round_dbl(d, &nb, len, precision);
	else if (precision)
		nb[++i] = (int)d + '0';
	insert_point_sign_d(1, &nb, sign_point);
	return (nb);
}

void	char_nbr(int exp, char **nb, int i)
{
	if (exp >= 0 && exp <= 9)
	{
		(*nb)[++i] = '0';
		(*nb)[++i] = exp + '0';
	}
	if (exp > 9)
	{
		char_nbr(exp / 10, nb, i);
		char_nbr(exp % 10, nb, i);
	}
}

void	add_exp_sc(char **nb, char e, int exp)
{
	int i;
	i = ft_strlen(*nb);
	(*nb)[i] = e;
	(*nb)[++i] = exp < 0 ? '-' : '+';
	exp = exp < 0 ? -exp : exp;
	char_nbr(exp, nb, i);
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
	sign_point[1] = (flags->precision[num] == 0) ? 0 : 1;
	g = (sign_point[0]) ? -g : g;
	flags->precision[num] = (flags->precision[num]) ? flags->precision[num] : 1;
	exp = (g == 0.0) ? 0 : exposant_d(g);
	if ((exp < 0 && abs_value(exp) <= 4) ||
		(exp >= 0 && exp <= flags->precision[num] - 1))
		{
			nb = char_g_bis(g, flags->precision[num], sign_point, &exp);
			suppr_zero_g(&nb);
		}
	else
	{
		nb = char_sc(g, flags->precision[num], sign_point, &exp);
		add_exp_sc(&nb, c - 2, exp);
	}
	return (printing(&nb, arg, flags, num));
}