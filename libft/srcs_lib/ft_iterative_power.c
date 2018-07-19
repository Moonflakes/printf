/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 20:39:41 by mthiery           #+#    #+#             */
/*   Updated: 2017/09/12 15:42:08 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	ft_iterative_power(long long nb, long long power)
{
	long long r;

	r = nb;
	if (power < 0)
		return (0);
	if (power == 0 || nb == 1)
		return (1);
	while (1 < power)
	{
		nb = r * nb;
		power--;
	}
//	ft_putnbr(nb);
//	ft_putendl(" : itpow");
	return (nb);
}
