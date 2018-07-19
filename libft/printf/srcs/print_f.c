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

#include "../includes/printf.h"

void	nb_inf_zero(int *i, char *str)
{
	if (i[0] < 0)
	{
		i[0] = -i[0];
		while (i[0] > -1)
		{
			if (i[1] == 1)
			{
				str[i[1]] = '.';
				i[1]++;
			}
			str[i[1]] = '0';
			i[0]--;
			i[1]++;
		}
	}
}

char	*putf(char *nb, char *sign_nb, int precision)
{
	int		i[3];
	char	*str;

	if (!(str = (char*)ft_memalloc(sizeof(char) * 11)))
		return (NULL);
	i[0] = ft_strlen(nb) - precision;
//	ft_putnbr(ft_strlen(nb));
//	ft_putendl(" : len");
//	ft_putnbr(i[0]);
//	ft_putendl(" : i0");
	i[2] = 0;
	i[1] = 0;
	if (i[0] == 0)
	{
		str[0] = '0';
		i[1] = 1;
		i[0] = i[0] + 1;
	}
//	ft_putendl(nb);
//	ft_putnbr(precision);
//	ft_putendl(" : pr");
	nb_inf_zero(i, str);
	while (nb[i[2]])
	{
//		ft_putnbr(i[1]);
//		ft_putendl(" : i1");
//		ft_putnbr(i[0]);
//		ft_putendl(" : i0");
		if (i[1] == i[0])
		{
//			ft_putendl("l");
			str[i[1]] = '.';
			i[1]++;
		}
		str[i[1]] = nb[i[2]];
		i[1]++;
		i[2]++;
	}
	str[i[1]] = '\0';
//	ft_putendl(str);
	ft_strdel(&nb);
	str = ft_strjoin_free(sign_nb, str, 0);
	return (str);
}

char	*make_zeros(int precision)
{
	int i;
	char *nb;

	i = 0;
	nb = ft_strdup("0");
	while(i < precision)
	{
		nb = ft_strjoin_free(nb, "0", 1);
		i++;
	}
	return (nb);
}

int		print_f(t_arg *arg, t_flags *flags, int num)
{
	long double	f;
	char		*nb;
	long double	i;
	char		*sign_nb;

	f = arg->d[flags->index_arg[num]];
	if (f == 0 && arg->precision[num] == 0)
		flags->precision[num] = 6;
//	if (f == 0x0)
//		ft_putendl("je suis negatif");
//	ft_putendl("");
//	ft_putnbr(f/100000000000);
//	ft_putendl(" : f");
//	ft_putnbr(flags->precision[num]);
//	ft_putendl(" : precision");
//	ft_putnbr(flags->width[num]);
//	ft_putendl(" : width");
	i = f * ft_power_double(10, flags->precision[num] + 1);
//	ft_putnbr(i/100000000000000000);
//	ft_putendl(" : i");
	sign_nb = ft_strdup("");
	if (f == 0)
	{
		nb = make_zeros(flags->precision[num] + 1);
	}
	else if (i < 0)
	{
		sign_nb = ft_strdup_del("-", sign_nb);
		nb = ft_dtoa(i * -1);
	}
	else
		nb = ft_dtoa(i);
//	ft_putendl(nb);
	nb = putf(round_f(nb), sign_nb, flags->precision[num]);
//	ft_putendl(nb);
	if (flags->htag[num] == 1 && flags->precision[num] == 0 && arg->precision[num] == 1)
		nb = ft_strjoin_free(nb, ".", 1);
//	ft_putendl(nb);
	return (printing(nb, arg, flags, num));
}
