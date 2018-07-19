/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:58:02 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 19:02:02 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				a;
	unsigned char	*u1;
	unsigned char	*u2;

	a = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (s1[a] || s2[a])
	{
		if ((s1[a] != s2[a]))
			return (u1[a] - u2[a]);
		a++;
	}
	return (0);
}
