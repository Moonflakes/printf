/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:25:36 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 14:23:23 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	*str;
	int		i;

	str = (char *)s;
	result = 0;
	i = 0;
	while (s[i])
	{
		if (ft_strchr(&s[i], c))
			result = ft_strchr(&s[i], c);
		i++;
	}
	if (i == 0 && c == '\0')
		return (str);
	return (result);
}
