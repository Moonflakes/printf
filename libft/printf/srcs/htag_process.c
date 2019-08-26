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

char	*ht_process_a(char *str, char a)
{
	int		i;
	char	*end;
	char	*start;

	i = -1;
	a = (ft_strchr("aA", a)) ? a + 15 : a;
	while (str[++i] != a)
		;
	end = ft_strdup(&str[i]);
	start = ft_strndup(str, i);
	ft_strdel(&str);
	str = ft_strjoin_free(ft_strjoin_free(start, ".", 1), end, 0);
	return (str);
}

char	*htag_process(char *str, t_arg *arg, t_flags *flags, int num)
{
	if (flags->htag[num] == 1)
	{
		if (ft_strchr("oO", arg->type[num]) && ((flags->precision[num] <= 1 ||
			flags->prpass == 0) && arg->ull[num] != 0))
			str = ft_strjoin_free("0", str, 2);
		if (ft_strchr("xX", arg->type[num]))
		{
			if (arg->ull[num] != 0)
				str = ft_strjoin_free(if_maj(ft_strdup("0x"),
					arg->type[num]), str, 0);
			else
				str = (flags->precision[num] == 0 && arg->precision[num] == 1) ?
					ft_strdup_del("", str) : str;
		}
		if (ft_strchr("gG", arg->type[num]))
			str = ht_process_g(str, flags->precision[num], arg->type[num] - 2);
		if (ft_strchr("aAeE", arg->type[num]))
			str = (ft_strchr(str, '.')) ? str :
				ht_process_a(str, arg->type[num]);
		if (ft_strchr("fF", arg->type[num]) && flags->precision[num] == 0)
			str = ft_strjoin_free(str, ".\0", 1);
	}
	str = (arg->ull[num] == 0 && flags->precision[num] == 0 &&
		ft_strchr("xX", arg->type[num])) ? ft_strdup_del("", str) : str;
	return (str);
}
