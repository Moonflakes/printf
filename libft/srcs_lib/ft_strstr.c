/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:32:39 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/20 19:08:50 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		n;
	int		a;
	char	*src;
	char	*to_find;

	n = 0;
	src = (char *)haystack;
	to_find = (char *)needle;
	if (ft_strlen(needle) == 0)
		return (src);
	while (src[n])
	{
		a = 0;
		while (to_find[a] == src[n + a])
		{
			if (to_find[a + 1] == '\0')
				return (src + n);
			a++;
		}
		n++;
	}
	return (0);
}
