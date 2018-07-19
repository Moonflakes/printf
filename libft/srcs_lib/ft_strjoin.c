/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:53:05 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 14:50:20 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i] && (str[i] = s1[i]))
			i++;
		while (s2[j] && (str[i] = s2[j]))
		{
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
