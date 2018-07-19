/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:37:56 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/20 15:37:21 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	char	*str;
	int		i;

	find = c;
	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			return (str + i);
		i++;
	}
	if (find == '\0')
		return (str + i);
	return (NULL);
}
