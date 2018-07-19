/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:00:06 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 19:00:59 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	*ft_range(int min, int max)
{
	int *tab;
	int i;
	int taille;

	i = 0;
	taille = max - min;
	if (min >= max)
		return (NULL);
	tab = (int*)ft_memalloc(sizeof(tab) * (taille + 1));
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
