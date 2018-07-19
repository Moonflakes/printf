/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mon_itoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:24:33 by mthiery           #+#    #+#             */
/*   Updated: 2018/04/20 14:27:22 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	nbase_len(long long nb, long long base)
{
	long long i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int			index_base(long long index)
{
	if (index <= 9)
		return (index);
	else
		return (index - 10 + 'A');
}

char		*ft_convert_base(long long nb, long long base, int neg)
{
	char		*b;
	long long	i;

	i = nbase_len(nb, base) - 1 + neg;
	if (!(b = (char*)ft_memalloc(sizeof(char) * nbase_len(nb, base) + 1)))
		return (NULL);
	b[i + 1] = '\0';
	while (nb > 0)
	{
		b[i] = index_base(nb % base) + '0';
		nb = nb / base;
		i--;
	}
	return (b);
}

char		*mon_itoabase(long long nb, long long base)
{
	char	*b;
	int		neg;

	neg = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	b = ft_convert_base(nb, base, neg);
	return (b);
}
