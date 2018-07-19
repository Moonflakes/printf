/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 17:17:38 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/10 13:43:26 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int a;
	unsigned int k;

	a = 0;
	k = 0;
	while (s1[a])
		a++;
	while (s2[k] && (k < n))
	{
		s1[k + a] = s2[k];
		k++;
	}
	s1[k + a] = '\0';
	return (s1);
}
