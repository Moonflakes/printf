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

#include "../includes/printf.h"

int	printing(char **str, t_arg *arg, t_flags *flags, int num)
{
	int i;

/*	if ((arg->type[num] == 'C' || (arg->type[num] == 'c' &&
		arg->length[num] == 1)) && (arg->i[flags->index_arg[num]] > 255 ||
		arg->i[flags->index_arg[num]] < 0))
	{
		ft_putstr("");
		i = -1;
	}*/
	if (arg->ret == -1)
	{
		i = -1;
	}
	else
	{
//		ft_putendl("");
//		ft_putstr(str);
//		ft_putendl(" : str");
		*str = process_flags(*str, arg, flags, num);
//		ft_putstr(str);
//		ft_putendl(" : str2");
//		if (arg->count_bn < arg->nb_bn)
			ft_putstr(*str);
		i = ft_strlen(*str);
	}
	ft_strdel(str);
//	ft_putendl("miou");
	verif_next_arg(arg, flags, num + 1);
//	ft_putendl("mia");
	return (i);
}

int interrupt(t_arg *arg, t_flags *flags)
{
	int num;

	num = 0;
	while (arg->type[num])
	{
		if ((arg->type[num] == 'C' || (arg->type[num] == 'c' &&
		arg->length[num] == 1)) && (arg->i[flags->index_arg[num]] > 255 ||
		arg->i[flags->index_arg[num]] < 0))
		{
			ft_putstr("");
			return (-1);
		}
		num++;
	}
	return (0);
}
