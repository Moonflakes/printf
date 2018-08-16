/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htag_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:24:54 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/03 14:53:06 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_zeros(char *nb, int precision)
{
	int len;
	int i;

	i = 0;
	while (nb[i] == '0' || nb[i] == '-' || nb[i] == '.')
		++i;
	i = (ft_strcmp(nb, "0.\0")) ? i : 0;
	len = (i >= 2) ? ft_strlen(nb) - i - 1 : ft_strlen(nb) - i - 2;
	i = ft_strlen(nb) - 1;
	while (++len < precision)
		nb[++i] = '0';
	return (nb);

}

char	*add_point(char *nb, int precision)
{
	int len;
	int sign;

	sign = (nb[0] == '-') ? 1 : 0;
	len = ft_strlen(nb);
	if (!ft_strchr(nb, '.') && len - sign <= precision)
		nb[len] = '.';
	return (nb);
}

char	*copy_nb(char *str, char *nb, int len)
{
	int		i;
	
	i = -1;
	while (++i < len)
		nb[i] = str[i];
	return (nb);
}

char	*add_rest(char *nb, char *str)
{
	char	*rest;
	int		i;
	int		j;

	rest = ft_strdup(ft_strchr(str, 'e'));
	j = ft_strlen(nb) - 1;
	i = -1;
	if (rest)
	{
		while (rest[++i])
			nb[++j] = rest[i];
		ft_strdel(&rest);
	}
	return (nb);

}

char	*ht_process_g(char *str, int precision, char e)
{
	char	*nb;
	int		len;
	int		len_e;

	len = ft_strlen(str) + precision + 1;
	len_e = ft_strlen(str) - ft_strlen(ft_strchr(str, e));
	if (!(nb = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	nb = add_rest(add_zeros(add_point(copy_nb(str, nb, len_e), precision), precision), str);
	ft_strdel(&str);
	return (nb);
}

char	*ht_process_a(char *str, char a)
{
	int i;
	char *end;
	char *start;

	i = 0;
	while (str[i] != a)
		i++;
	end = ft_strdup(&str[i]);
	start = ft_strndup(str, i);
	ft_strdel(&str);
	str = ft_strjoin_free(ft_strjoin_free(start, ".", 1), end, 0);
	return (str);
}

char	*htag_process(char *str, t_arg *arg, t_flags *flags, int num)
{
//	ft_putendl("");
//	ft_putnbr(arg->precision[num]);
//	ft_putendl(" : arg pr");
//	ft_putnbr(flags->precision[num]);
//	ft_putendl(" : flags pr");
//	ft_putnbr(flags->htag[num]);
//	ft_putendl(" : htag");
//	ft_putunsignednbr(arg->ull[num]);
//	ft_putendl(" : ull");
//	ft_putstr(str);
//	ft_putendl(" : str");
//	ft_putchar(arg->type[num]);
//	ft_putendl(" : type");
//	ft_putnbr(flags->prpass);
//	ft_putendl(" : pr pass");
	if (flags->htag[num] == 1)
	{
		if ((arg->type[num] == 'o' || arg->type[num] == 'O') &&
		((flags->precision[num] <= 1 || flags->prpass == 0) && arg->ull[num] != 0))
			str = ft_strjoin_free("0", str, 2);
		if (arg->type[num] == 'x' || arg->type[num] == 'X')
		{
			if (arg->ull[num] != 0)
				str = ft_strjoin_free(if_maj(ft_strdup("0x"), arg->type[num]), str, 0);
			str = (arg->ull[num] == 0 && flags->precision[num] == 0 
				&& arg->precision[num] == 1) ? ft_strdup_del("", str) : ft_strdup_free(str);
		}
		if (arg->type[num] == 'g' || arg->type[num] == 'G')
			str = ht_process_g(str, flags->precision[num], arg->type[num] - 2);
		if ((arg->type[num] == 'a' || arg->type[num] == 'A') && (flags->precision[num] == 0
			|| (arg->precision[num] == 0 && flags->precision[num] == 1)))
		{
			str = ht_process_a(str, arg->type[num] + 15);
		}
		if ((arg->type[num] == 'e' || arg->type[num] == 'E') && (flags->precision[num] == 0
			|| (arg->precision[num] == 0 && flags->precision[num] == 1)))
		{
			str = ht_process_a(str, arg->type[num]);
		}
		if ((arg->type[num] == 'f' || arg->type[num] == 'F') && flags->precision[num] == 0)
			str = ft_strjoin_free(str, ".\0", 1);
	}
	if (arg->ull[num] == 0 && flags->precision[num] == 0 && (arg->type[num] == 'x' || arg->type[num] == 'X'))
	{
		str = ft_strdup_del("", str);
	}
	return (str);
}
