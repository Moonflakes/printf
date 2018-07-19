/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 09:29:52 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 09:51:05 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_arg	*init_struct_arg(int len)
{
	t_arg *arg;

	if (!(arg = (t_arg*)ft_memalloc(sizeof(t_arg))))
		return (NULL);
	if (!(arg->precision = ft_memalloc(sizeof(int) * len)))
		ft_putendl("STOOOOOOOOOOOOOOOOP!!!!!!!!!!!!!!!");
//	ft_bzero(arg->precison, len);
	arg->type = ft_memalloc(sizeof(char) * (len + 1));
	arg->size = ft_memalloc(sizeof(size_t) * len);
	arg->strp = ft_memalloc(sizeof(char*) * (len + 1));
	arg->length = ft_memalloc(sizeof(int) * len);
	arg->i = ft_memalloc(sizeof(long long) * len);
	arg->ull = ft_memalloc(sizeof(unsigned long long) * len);
	arg->d = ft_memalloc(sizeof(long double) * len);
	arg->s = ft_memalloc(sizeof(int*) * len);
	return (arg);
}

t_flags	*init_struct_flags(int len)
{
	t_flags *flags;

	if (!(flags = (t_flags*)ft_memalloc(sizeof(t_flags))))
		return (NULL);
	flags->prpass = 0;
	flags->htag = ft_memalloc(sizeof(int) * len);
	flags->zero = ft_memalloc(sizeof(int) * len);
	flags->left = ft_memalloc(sizeof(int) * len);
	flags->plus = ft_memalloc(sizeof(int) * len);
	flags->space = ft_memalloc(sizeof(int) * len);
	flags->asterix_w = ft_memalloc(sizeof(int) * len);
	flags->asterix_p = ft_memalloc(sizeof(int) * len);
	flags->cote = ft_memalloc(sizeof(int) * len);
	flags->dollar = ft_memalloc(sizeof(int) * len);
	flags->index_arg = ft_memalloc(sizeof(int) * len);
	flags->precision = ft_memalloc(sizeof(int) * len);
	flags->width = ft_memalloc(sizeof(size_t) * len);
	return (flags);
}

t_int	*init_struct_int(char *str, int num)
{
	t_int *inc;

	if (!(inc = (t_int*)ft_memalloc(sizeof(t_int))))
		return (NULL);
	inc->str = str;
	inc->num = num;
	return (inc);
}

t_sign	*init_struct_sign(char a, t_arg *arg, int num)
{
	t_sign *sign;

	if (!(sign = (t_sign*)ft_memalloc(sizeof(t_sign))))
		return (NULL);
	sign->a = a;
	sign->pr = arg->precision[num];
	return (sign);
}

t_g		*init_struct_g(t_arg *arg, t_flags *flags, int num, char c)
{
	t_g	*val;

	if (!(val = (t_g*)ft_memalloc(sizeof(t_g))))
		return (NULL);
	val->i = (arg->precision[num] == 1 && flags->precision[num] != 0) ?
		-(flags->precision[num]) : -(flags->precision[num]) + 1;
//	if (arg->d[flags->index_arg[num]] != 0 && arg->d[flags->index_arg[num]] != 1 && flags->precision[num] != 0)
		val->sign_nb = ft_strdup("");
	val->c = (c == 'g') ? 'e' : 'E';
	val->num = num;
	return (val);
}
