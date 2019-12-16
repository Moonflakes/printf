/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:55:42 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/10 12:56:10 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_recursive(char *str, unsigned long long jack, unsigned int base,
							unsigned long long i)
{
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

char		*ft_uitoabase(unsigned long long jack, unsigned int base)
{
	unsigned long long	i;
	char				*str;
	int					count;

	i = jack;
	count = 0;
	while (i > 0)
	{
		i = i / base;
		count++;
	}
	if (base < 2 || !(str = (char*)ft_memalloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	if (jack == 0)
	{
		ft_strdel(&str);
		str = ft_strdup("0");
		return (str);
	}
	ft_recursive(str, jack, base, ft_iterative_power(base, count - 1));
	return (str);
}
