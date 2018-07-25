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
/*
static void	ft_recursive(char *str, long long jack, int base, long long i)
{
	if (jack < 0)
	{
		*str = '-';
		ft_recursive((str + 1), -jack, base, i);
		return ;
	}
	if (i >= base)
	{
		if ((jack / i) < 10)
			*str = jack / i + '0';
		else
			*str = jack / i - 10 + 'A';
		ft_recursive((str + 1), (jack % i), base, (i / base));
		return ;
	}
	if ((jack / i) < 10)
		*str = jack + '0';
	else
		*str = jack - 10 + 'A';
}

char		*ft_itoabase(long long jack, int base)
{
	long long	i;
	int		neg;
	char	*str;
	int		count;

	i = 1;
	neg = 0;
	count = 0;
	if (jack <= 0)
		neg = 1;
	while (i <= jack || (i * -neg) >= jack)
	{
		i = i * base;
		count++;
	}
	if (base < 2 || !(str = (char*)malloc(sizeof(char) * (count + neg + 1))))
		return (NULL);
	str[count + neg] = '\0';
	if (jack == 0)
	{
		str[0] = '0';
		return (str);
	}
	ft_recursive(str, jack, base, (i / base));
	return (str);
}
*/

char	*ft_itoabase(long long jack, int base)
{
	long long	i;
	int			sign;
	int			len;
	char		*str;

	sign = jack < 0 ? 1 : 0;
	jack < 0 ? jack = -jack : 0;

}
