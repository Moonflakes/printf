/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:38:56 by mthiery           #+#    #+#             */
/*   Updated: 2018/06/07 13:38:59 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_dtoa(long double n)
{
	long long   i;
    long long   j;
    int         k;
    char        *str;

    i = 0;
    j = 0;
//    ft_putnbr(n);
//    ft_putendl(" : ndtoa");
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
    while (i > 0)
    {
        k = n * 10;
        n = n * 10 - k;
        str[j] = k + '0';
        j++;
        i--;
    }
//    ft_putstr(str);
//    ft_putendl(" : dtoa");
	return (str);
}
