/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power_double.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:46:06 by mthiery           #+#    #+#             */
/*   Updated: 2018/06/07 13:46:08 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double	ft_iterative_power_double(long double nb, long double power)
{
	long double r;

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
	return (nb);
}

