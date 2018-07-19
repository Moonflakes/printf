/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:04:05 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/10 15:04:24 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long nbb;

	nbb = n;
	if (nbb < 0 && nbb >= -2147483648)
	{
		ft_putchar_fd('-', fd);
		nbb = nbb * (-1);
	}
	if (nbb >= 0 && nbb <= 9)
	{
		ft_putchar_fd(nbb + '0', fd);
	}
	if (nbb > 9)
	{
		ft_putnbr_fd(nbb / 10, fd);
		ft_putnbr_fd(nbb % 10, fd);
	}
}
