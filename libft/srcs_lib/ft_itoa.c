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

char	*ft_itoa(long long n)
{
	unsigned long long	a;
	char				*str;
	int					sign;
	int					len;

	a = 10;
	len = 1;
	sign = n < 0 ? 1 : 0;
	n < 0 ? n = -n : 0;
	while (a - 1 < (unsigned long long)n && ++len)
		a *= 10;
	a /= 10;
	if (!(str = ft_memalloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	sign ? str[0] = '-' : 0;
	len = sign;
	while (a >= 1)
	{
		str[len++] = (n / a) + '0';
		n %= a;
		a /= 10;
	}
	return (str);
}
