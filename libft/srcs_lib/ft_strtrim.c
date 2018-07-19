/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:53:56 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 15:41:41 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	begin;
	unsigned int	nd;

	i = 0;
	begin = 0;
	if (s)
	{
		nd = ft_strlen(s);
		while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
			begin++;
		while (nd && (s[nd - 1] == 32 || (s[nd - 1] >= 9 && s[nd - 1] <= 10)))
			nd--;
		if (!(str = (char*)ft_memalloc(sizeof(char) * (nd - begin + 1))))
			return (NULL);
		while (nd && begin < nd && (str[i] = s[begin]))
		{
			i++;
			begin++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
