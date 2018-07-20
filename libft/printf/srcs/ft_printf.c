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

#include "../includes/printf.h"

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
	if (arg->type[i[1]] == 'n')
		*arg->s[i[1]] = i[2];
}

void	print_rest(int *i, const char *format/*, t_arg *arg, t_flags *flags*/)
{
	if (i[2] != -1)
	{
		i[0] = ft_color(&format[i[0]], i[0]);
//		ft_putendl("");
//		ft_putnbr(arg->nb_bn);
//		ft_putendl(" : nb bn");
//		ft_putnbr(arg->count_bn);
//		ft_putendl(" : compteur bn");
//		if (!(arg->type[i[1]] == 'c' && arg->i[flags->index_arg[i[1]]] == 0
//			&& !arg->type[i[1] + 1]))
//		{
//			if (arg->count_bn < arg->nb_bn)
				ft_putchar(format[i[0]]);
//			else
//			{
//				if (i[3] == 0 && arg->nb_bn != 0)
//					ft_putchar('\n');
//				i[3]++;
//			}
//		}
		i[2]++;
	}
	i[0]++;
}

int		nb_bn(const char *format)
{
	int i;
	int bn;

	i = 0;
	bn = 0;
	while (format[i])
	{
		if (format[i] == '\n')
		{
			bn++;
		}
		i++;
	}
	return (bn);
}



void init_struct_arg2(t_arg *arg, int len)
{
	//t_arg *arg;

	//if (!(arg = (t_arg*)ft_memalloc(sizeof(t_arg))))
	//	return (NULL);
	(arg)->precision = ft_memalloc(sizeof(int*) * len);
//	ft_bzero(arg->precison, len);
	(arg)->type = ft_memalloc(sizeof(char) * (len + 1));
	(arg)->size = ft_memalloc(sizeof(size_t) * len);
	(arg)->strp = ft_memalloc(sizeof(char*) * (len + 1));
	(arg)->length = ft_memalloc(sizeof(int) * len);
	(arg)->i = ft_memalloc(sizeof(long long) * len);
	(arg)->ull = ft_memalloc(sizeof(unsigned long long) * len);
	(arg)->d = ft_memalloc(sizeof(long double) * len);
	(arg)->s = ft_memalloc(sizeof(int*) * len);
}

void	init_struct_flags2(t_flags *flags, int len)
{
//	t_flags *flags;

//	if (!(flags = (t_flags*)ft_memalloc(sizeof(t_flags))))
//		return (NULL);
	(flags)->prpass = 0;
	(flags)->htag = ft_memalloc(sizeof(int) * len);
	(flags)->zero = ft_memalloc(sizeof(int) * len);
	(flags)->left = ft_memalloc(sizeof(int) * len);
	(flags)->plus = ft_memalloc(sizeof(int) * len);
	(flags)->space = ft_memalloc(sizeof(int) * len);
	(flags)->asterix_w = ft_memalloc(sizeof(int) * len);
	(flags)->asterix_p = ft_memalloc(sizeof(int) * len);
	(flags)->cote = ft_memalloc(sizeof(int) * len);
	(flags)->dollar = ft_memalloc(sizeof(int) * len);
	(flags)->index_arg = ft_memalloc(sizeof(int) * len);
	(flags)->precision = ft_memalloc(sizeof(int) * len);
	(flags)->width = ft_memalloc(sizeof(size_t) * len);
//	return (flags);
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
//		arg = ft_memalloc(sizeof(t_arg));
		init_struct_arg2(&arg, nb_prct(format));
//		arg = init_struct_arg(nb_prct(format));
//		flags = ft_memalloc(sizeof(t_flags));
		init_struct_flags2(&flags, nb_prct(format));
		//flags = init_struct_flags(nb_prct(format));
		num_arg(format, &arg, &flags);
		stock_arg(ap, &arg, &flags);
		arg.nb_bn = nb_bn(format);
//		i[2] = interrupt(arg, flags); // len
		if (i[2] == 0)
		{
			while (format[i[0]])
			{
//				ft_putchar('*');
//				ft_putchar(format[i[0]]);
//				ft_putendl(" : fomart[i]");
				i[0] = ft_color(&format[i[0]], i[0]);
				if (format[i[0]] == '%')
					print_args(i, &arg, &flags);
//				if (format[i[0]] == '\n')
//					arg->count_bn++;
				if (format[i[0]] && format[i[0]] != '%')
					print_rest(i, format/*, arg, flags*/);
			}
		}
//		free_struct(&arg, &flags);
	}
	va_end(ap);
	return (i[2]);
}
