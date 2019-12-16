/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:40:45 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:41:33 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	extract_arg(va_list ap, t_arg *arg, t_flags *flags, int num)
{
	if (flags->asterix_w[num] == 1)
		flags->width[num] = va_arg(ap, int);
	if (flags->asterix_p[num] == 1)
		flags->precision[num] = va_arg(ap, int);
	if (ft_strchr("cCdDi", arg->type[num]))
		arg->i[flags->index_arg[num]] = (arg->length[num] == 0) ?
									va_arg(ap, int) : va_arg(ap, long long);
	if (ft_strchr("uUoOxXpb", arg->type[num]))
		arg->ull[flags->index_arg[num]] = (arg->length[num] == 0 &&
		arg->type[num] != 'p') ?
					va_arg(ap, unsigned int) : va_arg(ap, unsigned long long);
	if (ft_strchr("sSn", arg->type[num]))
		arg->s[flags->index_arg[num]] = va_arg(ap, int*);
	if (ft_strchr("fFeEgGaA", arg->type[num]))
		arg->d[flags->index_arg[num]] = (arg->length[num] == 0) ?
								va_arg(ap, double) : va_arg(ap, long double);
}

void	stock_arg(va_list ap, t_arg *arg, t_flags *flags)
{
	int i;
	int num;

	num = 0;
	while (num < arg->nb_arg)
	{
		if (arg->dollar == 1)
		{
			i = 0;
			while (i < arg->nb_prct)
			{
				if (flags->index_arg[i] == num)
				{
					if (arg->type)
						extract_arg(ap, arg, flags, num);
					break ;
				}
				i++;
			}
		}
		else if (arg->type)
			extract_arg(ap, arg, flags, num);
		num++;
	}
}
