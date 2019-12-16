/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:13:15 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:37:47 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	order_print(int order, char **str)
{
	int a;

	if (order)
	{
		ft_putchar('\0');
		ft_putstr(*str);
	}
	else
	{
		a = ft_strlen(*str) - 1;
		*str = a < 0 ? *str : ft_strsub_free(*str, 0, a);
		ft_putstr(*str);
		ft_putchar('\0');
	}
}

int		printing(char **str, t_arg *arg, t_flags *flags, int num)
{
	int i;

	if (arg->ret == -1)
		i = -1;
	else
	{
		*str = process_flags(*str, arg, flags, num);
		if (!arg->i[flags->index_arg[num]] && (arg->type[num] == 'c' ||
			arg->type[num] == 'C') && flags->left[num])
			order_print(1, str);
		else if (!arg->i[flags->index_arg[num]] && (arg->type[num] == 'c' ||
			arg->type[num] == 'C') && !flags->left[num])
			order_print(0, str);
		else
			ft_putstr(*str);
		i = ft_strlen(*str);
	}
	ft_strdel(str);
	if (num + 1 < arg->nb_prct)
		verif_next_arg(arg, flags, num + 1);
	return (i);
}
