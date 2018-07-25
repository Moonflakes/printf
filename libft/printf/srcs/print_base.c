/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:22:17 by mthiery           #+#    #+#             */
/*   Updated: 2018/04/23 17:59:01 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*pad_precision(char **str, t_flags *flags, int num)
{
	int		i;
	int		j;
	char	*padstr;

	padstr = NULL;
	i = (str[0][0] == '-') ? ft_strlen(str[0]) : ft_strlen(str[0]) + 1;
//	ft_putendl("");
//	ft_putnbr(i);
//	ft_putendl(" : i");
//	ft_putnbr(flags->precision[num]);
//	ft_putendl(" : pr");
	if (flags->precision[num] >= i && flags->precision[num] != 0)
	{
		j = i + (flags->precision[num] - i) + 1;
		if (!(padstr = (char*)ft_memalloc(sizeof(char) * (j + 1))))
			return (NULL);
		while (j-- + 1 > 0)
		{
			while (--i >= 0)
			{
				if (str[0][i] == '-')
					break ;
				padstr[j--] = str[0][i];
			}
			if (str[0][i] == '-')
				padstr[0] = '-';
			padstr[j] = (padstr[j] == '-') ? '-' : '0';
		}
		ft_strdel(str);
		str[0] = ft_strdup(padstr);
		flags->prpass = 1;
//		ft_putendl("je passe la");
	}
//	ft_putendl("");
//	ft_putstr(str);
//	ft_putendl(" : str");
	return (str[0]);
}

int		ft_nblen(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		i++;
	}
	if (nb == 0)
		i = 1;
	return (i);
}

int		print_nb(t_arg *arg, t_flags *flags, int num)
{
	long long	i;
	char		*str;
//	char		*tmp;

//	tmp = NULL;
	i = arg->i[flags->index_arg[num]];
	str = NULL;
//	ft_putnbr(i);
//	ft_putendl(" : i");
//	ft_putnbr(flags->precision[num]);
//	ft_putstr(" - ");
//	ft_putnbr(arg->precision[num]);
//	ft_putendl(" : precision");
	if (i == 0 && flags->precision[num] == 1 && arg->precision[num] == 1)
		str = ft_memalloc(sizeof(char));
	else
	{
		str = ft_itoa(i);
		//str = pad_precision(&str, flags, num);
//		ft_strdel(&str);
	}
	return (printing(&str, arg, flags, num));
}

int		print_base(int base, t_arg *arg, t_flags *flags, int num)
{
	unsigned long long	i;
	char		*str;

	i = arg->ull[flags->index_arg[num]];
//	ft_putendl("");
//	ft_putunsignednbr(i);
//	ft_putendl(" : i");
	if (i == 0 && flags->precision[num] == 1 && arg->precision[num] == 1
		&& (arg->type[num] == 'u' || arg->type[num] == 'U') &&
		flags->width[num] == 0)
		str = ft_strdup("");
	else
	{
		str = (arg->type[num] == 'u' || arg->type[num] == 'U' ||
			arg->length[num] == 3 || (arg->length[num] == 1 &&
			arg->type[num] == 'o') || arg->type[num] == 'O') ?
			ft_uitoabase(i, base) : ft_itoabase(i, base);
		str = pad_precision(&str, flags, num);
	}
	return (printing(&str, arg, flags, num));
}

int		print_hex(char c, t_arg *arg, t_flags *flags, int num)
{
	unsigned long long	i;
	char		*x;

	i = arg->ull[flags->index_arg[num]];
	x = (arg->length[num] == 1 || arg->length[num] == 3) ?
		ft_uitoabase(i, 16) : ft_itoabase(i, 16);
	i = 0;
	if (c == 'x')
	{
		while (x[i])
		{
			x[i] = ft_tolower(x[i]);
			i++;
		}
	}
	x = pad_precision(&x, flags, num);
	return (printing(&x, arg, flags, num));
}