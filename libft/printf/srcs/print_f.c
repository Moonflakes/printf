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
	len = (precision + 2 < 1 - *exp) ? precision + 2 : *exp + 1 + precision + 2;
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

int		reset_nb(char **nb, int i, int precision)
{
	char	*tmp;
	int		a;

	a = 0;
	while (--i >= 0 && (*nb)[i] == '9')
		(*nb)[i] = '0';
	if (++i == 0 && (*nb)[i] == '0')
	{
		if (precision) // du coup plus le meme malloc...
		{
			(*nb)[i] = '0';
			tmp = ft_strjoin("1", *nb);
			ft_strdel(nb);
			*nb = tmp;
			a = 1;
		}
		else
			(*nb)[i] = '1';
		return (a);
	}
//	ft_putchar((*nb)[i]);
//	ft_putendl(" : nb[i]");
	if (i && (*nb)[i] == '0')
		--i;
	(*nb)[i] = (*nb)[i] + 1;
//	ft_putendl("je passe ici");
	return (a);
}

int		round_dbl(long double d, char **nb, int i, int precision)
{
	int a;

	a = 0;
//	ft_putstr(*nb);
//	ft_putendl(" : nb");
	if ((int)((d - (int)d) * 10) >= 8 && (int)d == 9)
	{
		(*nb)[++i] = '0';
		a = reset_nb(nb, i, precision);
	}
	else
	{
		if (precision)
		{
			d += 1;
			(*nb)[++i] = (int)d + '0';
		}
		else
			(*nb)[i] = (*nb)[i] + 1;
	}
	return (a);
}

void	start_d(unsigned long long n, int *i, char **nb)
{
	char				value;
	unsigned long long	cast;

	cast = n;
	if (cast > 9)
		start_d(cast / 10, i, nb);
	value = '0' + cast % 10;
	(*nb)[++(*i)] = value;
}

void	end_d(long double *d, int precision, int *i, char **nb)
{
	int j;

	j = 0;
	while (++j < precision)
	{
		(*d) *= 10;
		(*nb)[++(*i)] = (int)(*d) + '0';
		(*d) -= (int)(*d);
	}
}

void insert_point_sign_d(int place_point, char **nb, int *sign_point)
{
	int len;

	len = ft_strlen((*nb));
	if (sign_point[0])
		ft_memmove((*nb) + 1, (*nb), sizeof(char) * len);
	if (sign_point[1])
		ft_memmove((*nb) + place_point + sign_point[0] + 1, (*nb) + place_point + sign_point[0], sizeof(char) * (len - place_point));
	sign_point[0] ? (*nb)[0] = '-' : 0;
	sign_point[1] ? (*nb)[place_point + sign_point[0]] = '.' : 0;

}

char	*char_d(long double d, int precision, int *sign_point, int exp)
{
	int			i;
	int			len;
	char		*nb;

	i = -1;
	len = ft_nblen((unsigned long long)d) + sign_point[0] +
		sign_point[1] + precision + ft_nblen(exp);
//	ft_putnbr(len);
//	ft_putendl(" : len malloc");
	if (!(nb = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	start_d((unsigned long long)d, &i, &nb);
	len = i + 1;
	d -= (uint64_t)d;
	end_d(&d,  precision, &i, &nb);
	d *= 10;
	if ((int)((d - (int)d) * 10) >= 5)
		len = len + round_dbl(d, &nb, i, precision);
	else if (precision)
		nb[++i] = (int)d + '0';
	insert_point_sign_d(len, &nb, sign_point);
	return (nb);
}

int		print_f(t_arg *arg, t_flags *flags, int num)
{
	int			sign_point[2];
//	int			exp;
	long double	f;
	char		*nb;
	int			u;	

	f = arg->d[flags->index_arg[num]];
	u = *(((size_t *)&arg->d[flags->index_arg[num]]) + 1);
	sign_point[0] = ((f == 0 && u != 0) || f < 0) ? 1 : 0;
	sign_point[1] = (flags->precision[num] == 0) ? 0 : 1;
	f = f < 0 ? -f : f;
//	exp = (f == 0.0) ? 0 : exposant_d(f);
	nb = char_d(f, flags->precision[num], sign_point, 0);
//	nb = char_f(f, flags->precision[num], &exp);
//	nb = insert_point_sign(nb, exp, sign_point, 0);
	return (printing(&nb, arg, flags, num));
}
