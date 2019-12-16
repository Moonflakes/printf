/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:58:20 by mthiery           #+#    #+#             */
/*   Updated: 2018/06/12 09:58:23 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup_del(const char *s1, char *s2)
{
	int		len;
	char	*dest;

	dest = NULL;
	if (s2)
		ft_strdel(&s2);
	if (s1)
	{
		len = ft_strlen(s1);
		if (!(dest = (char*)ft_memalloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strcpy(dest, s1);
	}
	return (dest);
}
