/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 20:11:53 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/20 15:39:57 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	a;
	unsigned char	*u1;
	unsigned char	*u2;

	a = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while ((s1[a] || s2[a]) && (a < n))
	{
		if (s1[a] != s2[a])
			return (u1[a] - u2[a]);
		a++;
	}
	return (0);
}
