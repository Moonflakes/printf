/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:56:32 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/10 12:56:38 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putunsignednbr(unsigned long long n)
{
	unsigned long long nbb;

	nbb = n;
	if (nbb <= 9)
		ft_putchar(nbb + '0');
	if (nbb > 9)
	{
		ft_putunsignednbr(nbb / 10);
		ft_putunsignednbr(nbb % 10);
	}
}
