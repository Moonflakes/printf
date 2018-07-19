/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:01:01 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/20 15:36:14 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	l;
	unsigned int	i;

	str = (unsigned char*)s;
	l = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == l)
			return (str + i);
		i++;
	}
	return (NULL);
}
