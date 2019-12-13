/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:19:24 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 10:38:54 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "funct.h"

void	verif_next_arg(t_arg *arg, t_flags *flags, int next)
{
	char *sw_next;

	if (arg->i && arg->i[flags->index_arg[next]])
	{
		if ((arg->type[next] == 'C' || (arg->type[next] == 'c'
			&& arg->length[next] == 1)) && !(arg->i[flags->index_arg[next]]
			<= 127 && arg->i[flags->index_arg[next]] >= 0))
		{
			sw_next = printable_w(arg->i[flags->index_arg[next]], arg);
			if (mblen(sw_next, MB_CUR_MAX) == -1)
				arg->ret = -1;
			ft_strdel(&sw_next);
		}
	}
}

int		print_char(t_arg *arg, t_flags *flags, int num)
{
	char c;
	char *str;

	c = arg->i[flags->index_arg[num]];
	setlocale(LC_ALL, "");
	if ((arg->type[num] == 'c' && arg->length[num] == 0) ||
		(arg->i[flags->index_arg[num]] <= 127 &&
		arg->i[flags->index_arg[num]] >= 0))
	{
		str = ft_strndup(&c, 1);
	}
	else
	{
		str = printable_w(arg->i[flags->index_arg[num]], arg);
		if (mblen(str, MB_CUR_MAX) == -1)
			arg->ret = -1;
	}
	return (printing(&str, arg, flags, num));
}

int		what_base(t_arg *arg, int num)
{
	if (arg->type[num] == 'u' || arg->type[num] == 'U')
		return (10);
	if (arg->type[num] == 'o' || arg->type[num] == 'O')
		return (8);
	if (arg->type[num] == 'b')
		return (2);
	return (0);
}

int		if_length(t_arg *arg, t_flags *flags, int num)
{
	if (arg->length[num] == 1)
		return (print_la(arg->type[num], arg, flags, num));
	else
		return (print_a(arg->type[num], arg, flags, num));
	return (0);
}

int		print_arg(t_arg *arg, t_flags *flags, int num)
{
	char	*pct;
	int		i;

	i = 0;
	if (arg->type && arg->type[num] != 'n')
	{
		if (arg->type[num] == '%')
		{
			pct = ft_strdup("%");
			return (printing(&pct, arg, flags, num));
		}
		while (tabf[i].cond1 && !ft_strchr(tabf[i].cond1, arg->type[num]))
			++i;
		if (tabf[i].cond2)
			return (tabf[i].cond2 == 1 ? (tabf[i].f2(arg->type[num], arg, flags,
			num)) : (tabf[i].f2(what_base(arg, num), arg, flags, num)));
		else
			return (tabf[i].f1(arg, flags, num));
	}
	return (0);
}
