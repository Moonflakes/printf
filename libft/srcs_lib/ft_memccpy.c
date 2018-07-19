/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:01:50 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/20 15:36:06 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	i = 0;
	while (i < n && n != 0)
	{
		p_dst[i] = p_src[i];
		if (p_dst[i] == ch)
			return (dst + (i + 1));
		i++;
	}
	return (0);
}
