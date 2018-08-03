/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:39:36 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 14:18:02 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	free_tab_str(t_arg *arg)
{
	int i;

	i = 0;
	while (arg->strp[i] && arg->strp)
	{
		ft_memdel((void**)&arg->strp[i]);
		i++;
	}
	free((void*)arg->strp);
	/*i = 0;
	while (arg->s[i] && arg->s && arg->type[i] != 'n' && arg->type[i] != 's' && arg->type[i] != 'S')
	{
		ft_memdel((void**)&arg->s[i]);
		i++;
	}*/
	free((void*)arg->s);
//	ft_memdel((void**)arg->s);
}

void	free_struct(t_arg *arg, t_flags *flags)
{
	free_tab_str(arg);
	ft_memdel((void**)&arg->type);
	ft_memdel((void**)&arg->size);
	ft_memdel((void**)&arg->length);
	ft_memdel((void**)&arg->i);
	ft_memdel((void**)&arg->ull);
	ft_memdel((void**)&arg->d);
	ft_memdel((void**)&arg->precision);
//	ft_memdel((void**)&arg);
	ft_memdel((void**)&flags->htag);
	ft_memdel((void**)&flags->zero);
	ft_memdel((void**)&flags->left);
	ft_memdel((void**)&flags->plus);
	ft_memdel((void**)&flags->space);
	ft_memdel((void**)&flags->asterix_p);
	ft_memdel((void**)&flags->asterix_w);
	ft_memdel((void**)&flags->cote);
	ft_memdel((void**)&flags->dollar);
	ft_memdel((void**)&flags->index_arg);
	ft_memdel((void**)&flags->precision);
	ft_memdel((void**)&flags->width);
//	ft_memdel((void**)&flags);
}

void	free_t_int(t_int *inc)
{
	ft_memdel((void**)&inc);
}

void	free_t_g(t_g *val)
{
	ft_memdel((void**)&val);
}
