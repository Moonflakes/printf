/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:57:53 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/10 15:00:31 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(long long n)
{
	long long nbb;

	nbb = n;
	if (nbb < 0 && nbb >= -2147483648)
	{
		ft_putchar('-');
		nbb = nbb * (-1);
	}
	if (nbb >= 0 && nbb <= 9)
	{
		ft_putchar(nbb + '0');
	}
	if (nbb > 9)
	{
		ft_putnbr(nbb / 10);
		ft_putnbr(nbb % 10);
	}
}
