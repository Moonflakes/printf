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

int		reset_nb(char **nb, int i, int precision, int len)
{
	char	*tmp;

	while (--i >= 0 && (*nb)[i] == '9')
		(*nb)[i] = '0';
	if (++i == 0 && (*nb)[i] == '0')
	{
		if (precision)
		{
			(*nb)[i] = '0';
			if (!(tmp = (char*)ft_memalloc(sizeof(char) * (len + 2))))
				return (0);
			ft_memcpy(tmp + 1, (*nb), sizeof(char) * len);
			tmp[0] = '1';
			ft_strdel(nb);
			*nb = tmp;
			return (1);	
		}
		else
			(*nb)[i] = '1';
		return (0);
	}
	if (i && (*nb)[i] == '0')
		--i;
	(*nb)[i] = (*nb)[i] + 1;
	return (0);
}

int		round_dbl(long double d, char **nb, int len, int precision)
{
	int a;
	int	i;

	a = 0;
	i = ft_strlen(*nb) - 1;
	if ((int)((d - (int)d) * 10) >= 8 && (int)d == 9)
	{
		(*nb)[++i] = '0';
		a = reset_nb(nb, i, precision, len);
	}
	else
	{
		if (precision && ++i <= len)
		{
			d += 1;
			(*nb)[i] = (int)d + '0';
		}
		else
			(*nb)[i] = (*nb)[i] + 1;
	}
	return (a);
}

int		ft_doublen(long double nb)
{
	int i;

	i = nb < 1 ? 1 : 0;
	while (nb > 1)
	{
		nb /= 10;
		++i;
	}
	return (i);
}

int		start_d(long double n, char **nb)
{
	int i;
	int u;
	long double a;

	a = 10;
	i = 0;
	u = -1;
	while (n / a > 1)
	{
		a *= 10;
		++i;
	}
	a /= 10;
	while (a >= 1)
	{
		(*nb)[++u] = (n / a) + '0';
		n -= (int)(n / a) * a;
		a /= 10;
	}
	return (i);
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
	int			point;
	char		*nb;

	len = ft_doublen(d) + sign_point[0] +
		sign_point[1] + precision + ft_nblen(exp);
	if (!(nb = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start_d(d, &nb);
	point = i + 1;
	d -= (uint64_t)d;
	end_d(&d,  precision, &i, &nb);
	d *= 10;
	if ((int)((d - (int)d) * 10) >= 5)
		point = point + round_dbl(d, &nb, len, precision);
	else if (precision)
		nb[++i] = (int)d + '0';
	insert_point_sign_d(point, &nb, sign_point);
	return (nb);
}

int		print_f(t_arg *arg, t_flags *flags, int num)
{
	int			sign_point[2];
	long double	f;
	char		*nb;
	int			u;	

	f = arg->d[flags->index_arg[num]];
	u = *(((size_t *)&arg->d[flags->index_arg[num]]) + 1);
	sign_point[0] = ((f == 0 && u != 0) || f < 0) ? 1 : 0;
	sign_point[1] = (flags->precision[num] == 0) ? 0 : 1;
	f = f < 0 ? -f : f;
	nb = char_d(f, flags->precision[num], sign_point, 0);
//	nb = char_f(f, flags->precision[num], &exp);
//	nb = insert_point_sign(nb, exp, sign_point, 0);
	return (printing(&nb, arg, flags, num));
}
