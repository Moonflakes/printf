/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:10:19 by mthiery           #+#    #+#             */
/*   Updated: 2018/01/24 11:46:26 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*dest;

	dest = NULL;
	if (s1)
	{
		if (!(dest = (char*)ft_memalloc(sizeof(char) * (len + 1))))
			return (NULL);
		ft_strncpy(dest, s1, len);
	}
	return (dest);
}
