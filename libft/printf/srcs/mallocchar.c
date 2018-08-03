/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mallocchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:38:37 by mthiery           #+#    #+#             */
/*   Updated: 2018/04/23 16:38:43 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*char_tab_malloc(int len)
{
	char *tab;

	if (!(tab = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (tab);
}

char		**str_tab_malloc(int len)
{
	char **tab;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		return (NULL);
	return (tab);
}

unsigned long long	*ull_tab_malloc(int len)
{
	unsigned long long *tab;

	if (!(tab = (unsigned long long*)ft_memalloc(sizeof(unsigned long long) * len)))
		return (NULL);
	return (tab);
}