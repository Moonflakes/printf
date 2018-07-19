/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:29:03 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/20 18:59:13 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	n;
	unsigned int	a;
	char			*src;
	char			*to_find;

	n = 0;
	src = (char *)haystack;
	to_find = (char *)needle;
	if (ft_strlen(needle) == 0)
		return (src);
	while (src[n] && n < len)
	{
		a = 0;
		while (to_find[a] == src[n + a])
		{
			if (to_find[a + 1] == '\0' && n + a < len)
				return (src + n);
			a++;
		}
		n++;
	}
	return (0);
}
