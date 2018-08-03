/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:12:40 by mthiery           #+#    #+#             */
/*   Updated: 2018/03/02 12:12:42 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_p(t_arg *arg, t_flags *flags, int num)
{
	unsigned long long	i;
	char				*p;

	i = arg->ull[flags->index_arg[num]];
	p = ft_strjoin_free(ft_strdup("0x"), ft_uitoabase(i, 16), 0);
	i = 0;
	while (p[i])
	{
		p[i] = ft_tolower(p[i]);
		i++;
	}
	return (printing(&p, arg, flags, num));
}
