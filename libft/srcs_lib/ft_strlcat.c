/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:32:39 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 19:02:39 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	if (size)
	{
		while (src[j] && i < (size - 1))
		{
			dst[i] = src[j];
			j++;
			i++;
		}
	}
	if (j)
	{
		dst[i] = '\0';
		return (ft_strlen(src) - j + i);
	}
	return (i + ft_strlen(src));
}
