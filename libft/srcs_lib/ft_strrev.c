/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 10:26:29 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 19:03:39 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	int		n;
	int		y;
	char	temp;

	n = 0;
	y = 0;
	while (str[n])
	{
		n++;
	}
	n--;
	while (y < n)
	{
		temp = str[n];
		str[n] = str[y];
		str[y] = temp;
		y++;
		n--;
	}
	return (str);
}
