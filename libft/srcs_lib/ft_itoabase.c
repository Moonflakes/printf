/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:30:36 by mthiery           #+#    #+#             */
/*   Updated: 2018/02/19 10:30:46 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_recursive(char *str, long long n, int base, unsigned long long i)
{
	if (i >= (unsigned long long)base)
	{
		if ((n / i) < 10)
			*str = n / i + '0';
		else
			*str = n / i - 10 + 'A';
		ft_recursive((str + 1), (n % i), base, (i / base));
		return ;
	}
	if ((n / i) < 10)
		*str = n + '0';
	else
		*str = n - 10 + 'A';
}

char	*ft_itoabase(long long n, int base)
{
	unsigned long long	i;
	int					sign;
	int					len;
	char				*str;

	i = 1;
	len = (n == 0 || (n == 2 && base == 2)) ? 1 : 0;
	sign = n < 0 ? 1 : 0;
	n < 0 ? n = -n : 0;
	while (i < (unsigned long long)n)
	{
		i *= base;
		++len;
	}
	i = (i / base < 1) ? i : i / base;
	if (base < 2 || !(str = ft_memalloc(sizeof(char) * (len + sign + 1))))
		return (NULL);
	if (sign)
	{
		str[0] = '-';
		ft_recursive((str + 1), n, base, i);
	}
	else
		ft_recursive(str, n, base, i);
	return (str);
}
