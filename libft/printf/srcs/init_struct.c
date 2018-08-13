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

#include "printf.h"

void	init_struct_arg(t_arg *arg, int len)
{
	(arg)->precision = ft_memalloc(sizeof(int*) * len);
	(arg)->type = ft_memalloc(sizeof(char) * (len + 1));
	(arg)->size = ft_memalloc(sizeof(size_t) * len);
	(arg)->strp = ft_memalloc(sizeof(char*) * (len + 1));
	(arg)->length = ft_memalloc(sizeof(int) * len);
	(arg)->i = ft_memalloc(sizeof(long long) * len);
	(arg)->ull = ft_memalloc(sizeof(unsigned long long) * len);
	(arg)->d = ft_memalloc(sizeof(long double) * len);
	(arg)->s = ft_memalloc(sizeof(int*) * len);
}

void	init_struct_flags(t_flags *flags, int len)
{
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
	(flags)->index_arg = ft_memalloc(sizeof(int) * (len));
	(flags)->precision = ft_memalloc(sizeof(int) * len);
	(flags)->width = ft_memalloc(sizeof(size_t) * len);
}
