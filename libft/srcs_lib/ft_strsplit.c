/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:54:43 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 14:34:38 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static unsigned int	nb_letters_word(const char *s, unsigned int a, char c)
{
	unsigned int mem;

	mem = 0;
	while (s[a] != c && s[a])
	{
		a++;
		mem++;
	}
	return (mem);
}

static unsigned int	nb_words(const char *s, char c)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static char			*ft_strdupl(const char *s, unsigned int a, char c)
{
	char			*dest;
	unsigned int	j;
	unsigned int	b;

	j = 0;
	if (s && c)
	{
		b = nb_letters_word(s, a, c);
		if (!(dest = (char*)ft_memalloc(sizeof(char) * (b + 1))))
			return (NULL);
		while (j < b)
		{
			dest[j] = s[a];
			j++;
			a++;
		}
		dest[j] = '\0';
		return (dest);
	}
	return (NULL);
}

char				**ft_strsplit(const char *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	a;

	a = 0;
	i = 0;
	if (s && c)
	{
		if (!(tab = (char**)ft_memalloc(sizeof(char*) * (nb_words(s, c) + 1))))
			return (NULL);
		while (s[a])
		{
			if (s[a] != c && s[a])
			{
				tab[i] = ft_strdupl(s, a, c);
				i++;
				a = a + nb_letters_word(s, a, c);
			}
			else
				a++;
		}
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
