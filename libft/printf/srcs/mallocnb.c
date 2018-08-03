/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:39:41 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 09:52:27 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	*ll_tab_malloc(int len)
{
	long long *tab;

	if (!(tab = (long long*)ft_memalloc(sizeof(long long) * len)))
		return (NULL);
	return (tab);
}

int			*int_tab_malloc(int len)
{
	int *tab;

	if (!(tab = (int*)ft_memalloc(sizeof(int) * len)))
		return (NULL);
	return (tab);
}

long double	*dbl_tab_malloc(int len)
{
	long double	*tab;
	int			i;

	i = 0;
	if (!(tab = (long double*)ft_memalloc(sizeof(long double) * len)))
		return (NULL);
	return (tab);
}

size_t		*size_t_tab_malloc(int len)
{
	size_t *tab;

	if (!(tab = (size_t*)ft_memalloc(sizeof(size_t) * len)))
		return (NULL);
	return (tab);
}

int			**long_tab_malloc(int len)
{
	int **tab;

	if (!(tab = (int**)ft_memalloc(sizeof(int*) * len)))
		return (NULL);
	return (tab);
}
