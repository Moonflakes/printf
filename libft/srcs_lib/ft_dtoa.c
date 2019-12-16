/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:38:56 by mthiery           #+#    #+#             */
/*   Updated: 2019/12/16 17:49:25 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	moumou(long double n, char **str, long long i)
{
	long long	j;
	int			k;

	j = 0;
	while (i > 0)
	{
		k = n * 10;
		n = n * 10 - k;
		*str[j] = k + '0';
		j++;
		i--;
	}
}

char	*ft_dtoa(long double n)
{
	long long	i;
	char		*str;

	i = 0;
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	if (i == 0)
		str = ft_strdup("0");
	else
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * (i))))
			return (NULL);
		str[i] = '\0';
	}
	moumou(n, &str, i);
	return (str);
}
