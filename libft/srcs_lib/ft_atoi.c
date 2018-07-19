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

static long long	ft_result(long long limit, long long neg, long long nbr)
{
	if (limit == 19 && neg == 0)
		return (-1);
	if (limit == 19 && neg == 1)
		return (0);
	if (neg == 1)
		return (-nbr);
	else
		return (nbr);
}

long long			ft_atoi(const char *str)
{
	long long i;
	long long nbr;
	long long neg;
	long long limit;

	nbr = 0;
	neg = 0;
	i = 0;
	limit = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && limit < 19)
	{
		nbr *= 10;
		nbr += (long long)str[i] - '0';
		i++;
		limit++;
	}
	return (ft_result(limit, neg, nbr));
}
