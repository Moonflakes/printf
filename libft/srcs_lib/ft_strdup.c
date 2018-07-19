/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:10:19 by mthiery           #+#    #+#             */
/*   Updated: 2018/01/11 14:45:59 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;

	dest = NULL;
	if (s1)
	{
		len = ft_strlen(s1);
		if (!(dest = (char*)ft_memalloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strcpy(dest, s1);
	}
	return (dest);
}
