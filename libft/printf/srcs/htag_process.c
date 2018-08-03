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

char	*add_zero(char *str, int count, int precision, int point_pr)
{
	if (count == 0)
		count = 1;
	if (point_pr != 1)
		precision = 6;
	while (count < precision)
	{
		str = ft_strjoin_free(str, "0", 1);
		count++;
	}
	return (str);
}

char	*if_sup_one(char *str, int i, int precision, int point_pr)
{
	char *s;
	char *tmp;
	int count;

	count = 0;
	if (!ft_strchr(str, '.'))
		str = ft_strjoin_free(str, ".", 1);
	while (str[i])
	{
		if (str[i] == '.')
			count--;
		if (str[i] == 'e')
		{
			s = ft_strndup(str, count + 1);
			tmp = ft_strdup(&str[count + 1]);
			ft_strdel(&str);
			s = add_zero(s, count, precision, point_pr);
	//		ft_putendl(s);
	//		ft_putendl(tmp);
			str = ft_strjoin_free(s, tmp, 0);
	//		ft_putendl(str);
			return (str);
			}
		i++;
		count++;
	}
	str = add_zero(str, count, precision, point_pr);
	return (str);
}

char	*if_inf_one(char *str, int i, int precision, int point_pr)
{
	int count;

	count = 0;
	if (ft_strlen(str) == 1)
		str = ft_strjoin_free(str, ".", 1);
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	str = add_zero(str, count, precision, point_pr);
	return (str);
}

char	*ht_process_g(char *str, int precision, int point_pr)
{
//	ft_putendl(str);
	if (str[0] != '-')
	{
		if (str[0] != '0')
		{
//			ft_putendl("la");
			str = if_sup_one(str, 0, precision, point_pr);
//			ft_putendl(str);
		}
		else
		{
//			ft_putendl("ici");
			// voir avec g = 0
			str = if_inf_one(str, 2, precision, point_pr);
		}
	}
	else
	{
		if (str[1] != '0')
		{
//			ft_putendl("par la");
			str = if_sup_one(str, 1, precision, point_pr);
		}
		else
		{
//			ft_putendl("par ici");
			// voir avec g = 0
			str = if_inf_one(str, 3, precision, point_pr);
		}
	}
	return (str);
}

char	*ht_process_a(char *str)
{
	int i;
	char *end;
	char *start;

	i = 0;
	while (str[i] != 'p')
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
			str = ht_process_g(str, flags->precision[num], arg->precision[num]);
		if ((arg->type[num] == 'a' || arg->type[num] == 'A') && (flags->precision[num] == 0
			|| (arg->precision[num] == 0 && flags->precision[num] == 1)))
		{
			str = ht_process_a(str);
		}
	}
	if (arg->ull[num] == 0 && flags->precision[num] == 0 && (arg->type[num] == 'x' || arg->type[num] == 'X'))
	{
		str = ft_strdup_del("", str);
	}
	return (str);
}
