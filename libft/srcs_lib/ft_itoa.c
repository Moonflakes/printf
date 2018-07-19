/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:56:12 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 17:26:47 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_result(long long nbb, long long nb_digit, char *str)
{
	long long i;
	long long neg;

	i = 0;
	neg = (nbb < 0) ? 1 : 0;
	if ((nbb / (ft_iterative_power(10, (nb_digit - (1 + neg))))) %
				10 == 0 && nbb != 0)
		nb_digit = nb_digit - (1 + neg);
	while (nb_digit > 0)
	{
		if (nbb < 0 && (neg = 1))
		{
			str[i++] = '-';
			nbb = nbb * (-1);
		}
		else
			neg = 0;
		str[i++] = ((nbb / (ft_iterative_power(10, (nb_digit - (1 + neg))))) %
					10) + '0';
		nb_digit = nb_digit - (1 + neg);
	}
}

char		*ft_itoa(long long n)
{
	char		*str;
	long long	i;
	long long	nb_digit;
	long long	nbb;

	i = 1;
	nb_digit = 0;
	nbb = n;
	while ((i <= nbb || -i >= nbb * 10 || (i - 1 == nbb && i - 1 != 9)) &&
			(i *= 10))
		nb_digit++;
	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (nb_digit + 1))))
		return (NULL);
	str[nb_digit] = '\0';
	ft_result(nbb, nb_digit, str);
	return (str);
}
