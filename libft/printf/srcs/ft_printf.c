/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:48:34 by mthiery           #+#    #+#             */
/*   Updated: 2018/01/26 16:27:16 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_args(int *i, t_arg *arg, t_flags *flags)
{
	int ret;

	i[1]++;
	i[0] = i[0] + arg->size[i[1]] + 1;
	ret = print_arg(arg, flags, i[1]);
	i[2] = (ret != -1) ? i[2] + ret : -1;
	i[2] = (arg->ret != -1) ? i[2] : -1;
	i[2] = ((arg->type[i[1]] == 'c' || arg->type[i[1]] == 'C')
			&& arg->i[i[1]] == 0) ? i[2] + 1 : i[2];
	// ft_putstr("\ni2 : ");
	// ft_putnbr(i[2]);
	// ft_putchar('\n');
	if (arg->type[i[1]] == 'n')
		*arg->s[i[1]] = i[2];
}

void	print_rest(int *i, const char *format)
{
	if (i[2] != -1)
	{
		i[0] = ft_color(&format[i[0]], i[0]);
		ft_putchar(format[i[0]]);
		i[2]++;
	}
	i[0]++;
}

int		ft_printf(const char *format, ...)
{
	int			i[4];
	va_list		ap;
	t_arg		arg;
	t_flags		flags;

	i[0] = 0; // i
	i[1] = -1; // num
	i[2] = 0;
	i[3] = 0; //passé par \n
	va_start(ap, format);
	if (format[i[0]])
	{
		init_struct_arg(&arg, nb_prct(format));
		init_struct_flags(&flags, nb_prct(format));
		num_arg(format, &arg, &flags);
		stock_arg(ap, &arg, &flags);
		if (i[2] == 0)
		{
			while (format[i[0]])
			{
				i[0] = ft_color(&format[i[0]], i[0]);
				if (format[i[0]] == '%')
					print_args(i, &arg, &flags);
				if (format[i[0]] && format[i[0]] != '%')
					print_rest(i, format);
			}
		}
		free_struct(&arg, &flags);
	}
	va_end(ap);
	return (i[2]);
}
