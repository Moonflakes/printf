/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:01:44 by mthiery           #+#    #+#             */
/*   Updated: 2018/04/24 10:15:03 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double	ft_power_double(long double nb, long long power)
{
	long double	r;

//	ft_putnbr(nb);
//	ft_putendl(" : nb");
//	ft_putnbr(power);
//	ft_putendl(" : power");
	r = nb;
	if (power == 0 || nb == 1)
		return (1);
	if (power < 0)
	{
		while (1 > power)
		{
			nb = nb / r;
			power++;
		}
	}
	if (power > 0)
	{
		while (1 < power)
		{
			nb = r * nb;
//			ft_putnbr(nb);
//			ft_putendl(" : nb la");
			power--;
		}
	}
//	ft_putnbr(nb);
//	ft_putendl(" : nb");
	return (nb);
}
