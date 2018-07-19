/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 14:37:50 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 19:01:42 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 1;
	if (str[0] >= 97 && str[0] <= 122)
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (!((str[i - 1] >= 'A' && str[i - 1] <= 'Z') || (str[i - 1] >= 'a'
		&& str[i - 1] <= 'z') || (str[i - 1] >= 48 && str[i - 1] <= 57)))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
		}
		if ((str[i - 1] >= 'A' && str[i - 1] <= 'Z') || (str[i - 1] >= 'a'
		&& str[i - 1] <= 'z') || (str[i - 1] >= 48 && str[i - 1] <= 57))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
		}
		i++;
	}
	if (str[i] == '\0')
		return (str);
	return (0);
}
