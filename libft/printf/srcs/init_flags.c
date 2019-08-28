/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:34:45 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 09:45:50 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_flags(t_arg *arg, int i, t_flags *flags, int num)
{
	char c;
	char before;

	c = arg->strp[num][i];
	before = arg->strp[num][i + 1];
	flags->htag[num] = (flags->htag[num] != 0 || c == '#') ? 1 : 0;
	flags->cote[num] = (flags->cote[num] != 0 || c == 39) ? 1 : 0;
	flags->left[num] = (flags->left[num] != 0 || c == '-') ? 1 : 0;
	flags->plus[num] = (flags->plus[num] != 0 || c == '+') ? 1 : 0;
	flags->zero[num] = (flags->zero[num] != 0 || ((c == '0' && ((before > '0'
		&& before <= '9') || before == '*')) && flags->left[num] != 1)) ?
		1 : 0;
	flags->space[num] = (flags->space[num] != 0 || (c == ' ' &&
		flags->plus[num] != 1)) ? 1 : 0;
	if ((arg->strp[num][i] == 'l' && !ft_strchr("aA", arg->type[num])) ||
		arg->strp[num][i] == 'L' || ft_strchr("DUOX", arg->type[num]))
		arg->length[num] = 1;
	if (arg->strp[num][i] == 'z' || arg->strp[num][i] == 'j')
		arg->length[num] = 3;
}

void	width(t_arg *arg, t_flags *flags, int num)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (flags->dollar[num])
	{
		while (arg->strp[num][i] != '$')
			i++;
		i++;
	}
	if (arg->precision[num] == 1)
	{
		i = -1;
		while (arg->strp[num][++i] != '.')
			if (arg->strp[num][i] == '*')
				flags->asterix_w[num] = 1;
		tmp = ft_strndup(arg->strp[num], i);
		flags->width[num] = extract_value(tmp, arg, flags, num);
		ft_strdel(&tmp);
		return ;
	}
	flags->width[num] = extract_value(&arg->strp[num][i], arg, flags, num);
}

void	if_point(t_arg *arg, t_flags *flags, int num, int i)
{
	arg->precision[num] = 1;
	flags->asterix_p[num] = (arg->strp[num][i + 1] == '*') ? 1 : 0;
	flags->precision[num] = extract_value(&arg->strp[num][i + 1], arg,
			flags, num);
	if (flags->precision[num] == 0)
		if (!ft_strchr("aAeEgGfFxXsS", arg->type[num]))
			flags->precision[num] = 1;
}

void	init_precision(t_arg *arg, t_flags *flags, int num)
{
	if (ft_strchr("eEgGfF", arg->type[num]))
		flags->precision[num] = 6;
	else if (ft_strchr("aA", arg->type[num]))
		flags->precision[num] = (arg->length[num]) ? 15 : 13;
	else
		flags->precision[num] = 1;
}

void	process_strp(t_arg *arg, int num, t_flags *flags)
{
	int		i;
	char	*tmp;

	i = -1;
	while (arg->strp[num][++i] && arg->strp[num])
	{
		if (arg->strp[num][i] == '$')
		{
			tmp = ft_strndup(arg->strp[num], i);
			flags->index_arg[num] = ft_atoi(tmp) - 1;
			ft_strdel(&tmp);
			flags->dollar[num] = 1;
			arg->dollar = 1;
		}
		if (arg->strp[num][i] == '.')
			if_point(arg, flags, num, i);
		init_flags(arg, i, flags, num);
	}
	if (!arg->precision[num])
		init_precision(arg, flags, num);
	width(arg, flags, num);
}
