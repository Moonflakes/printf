/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:04:06 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/20 16:30:22 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	ft_atoi(const char *str)
{
	long long i;
	long long nbr;
	long long neg;

	nbr = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	neg = (str[i] == '-') ? 1 : 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (long long)str[i] - '0';
		i++;
	}
	nbr = neg ? -nbr : nbr;
	return (nbr);
}
