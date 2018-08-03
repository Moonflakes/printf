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
//	ft_putnbr(flags->asterix_w[num]);
//	ft_putendl(" : *_w");
	if (flags->asterix_w[num] == 1)
		flags->width[num] = va_arg(ap, int);
	if (flags->asterix_p[num] == 1)
		flags->precision[num] = va_arg(ap, int);
	if (arg->type[num] == 'c' || arg->type[num] == 'C' || arg->type[num] == 'd'
	|| arg->type[num] == 'i' || arg->type[num] == 'D')
		arg->i[flags->index_arg[num]] = (arg->length[num] == 0) ? 
									va_arg(ap, int) : va_arg(ap, long long);
	if (arg->type[num] == 'u' || arg->type[num] == 'U' || arg->type[num] == 'o'
	|| arg->type[num] == 'O' || arg->type[num] == 'x' || arg->type[num] == 'X'
	|| arg->type[num] == 'p' || arg->type[num] == 'b')
		arg->ull[flags->index_arg[num]] = (arg->length[num] == 0 &&
		arg->type[num] != 'p') ? 
					va_arg(ap, unsigned int) : va_arg(ap, unsigned long long);
//	ft_putunsignednbr(arg->ull[flags->index_arg[num]]);
//	ft_putendl(" : ull");
	if (arg->type[num] == 's' || arg->type[num] == 'S' || arg->type[num] == 'n')
		arg->s[flags->index_arg[num]] = va_arg(ap, int*);
	if (arg->type[num] == 'f' || arg->type[num] == 'F' || arg->type[num] == 'e'
	|| arg->type[num] == 'E' || arg->type[num] == 'g' || arg->type[num] == 'G'
	|| arg->type[num] == 'a' || arg->type[num] == 'A')
		arg->d[flags->index_arg[num]] = (arg->length[num] == 0) ?
								va_arg(ap, double) : va_arg(ap, long double);
//	ft_putnbr(flags->precision[num]);
//	ft_putendl(" : pr before");
//	ft_putnbr(arg->length[num]);
//	ft_putendl(" : lenght");
//	ft_putchar(arg->type[num]);
//	ft_putendl(" : type");
	if (arg->precision[num] == 0)
		flags->precision[num] = (arg->d[num] != 0 || (arg->d[num] == 0 && (arg->type[num] == 'e' || arg->type[num] == 'E'))) ? 6 : 1;
//	ft_putnbr(flags->precision[num]);
//	ft_putendl(" : pr after");
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
		else
			if (arg->type)
				extract_arg(ap, arg, flags, num);
		num++;
	}
}
