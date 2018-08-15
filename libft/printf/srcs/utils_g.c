/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 11:40:01 by mthiery           #+#    #+#             */
/*   Updated: 2018/03/09 11:40:05 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*add_zero_g(char *nb, int *exp)
{
	char	*g;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	len = ft_strlen(nb) - *exp;
	if (!(g = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < len)
	{
		if (i < -*exp)
			g[i] = '0';
		else
			g[i] = nb[++j];
	}
	return (round_d(g, exp, 1));
}

char	*suppr_zero(char *nb)
{
	int i;

	i = ft_strlen(nb);
	while (nb[--i] == '0')
		nb[i] = '\0';
	if (nb[i] == '.')
		nb[i] = '\0';
	return (nb);
}

char	*insert_point_sign(char *nb, int exp, int sign, int d)
{
	char	*nbb;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(nb) + 1 + sign;
	i = -1;
	j = -1;
	if (!(nbb = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	if (sign)
		nbb[++i] = '-';
	while (++i < len)
	{
		nbb[i] = (i == exp + 1 + sign) ? '.' : nb[++j];
	}
	nbb[i] = '\0';
	ft_strdel(&nb);
	return (d) ? suppr_zero(nbb) : nbb;
}

char	*add_exp(char *nb, int exp, char e, int sign)
{
	char	*nbexp;
	char	sign_exp;
	int		len;
	int		i;

	len = ft_strlen(nb) + 3;
	sign_exp = (exp < 0) ? '-': '+';
	exp = abs_value(exp);
	i = -1;
	if (!(nbexp = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (nb[++i])
		nbexp[i] = nb[i];
	nbexp[i] = e;
	nbexp[++i] = sign_exp;
	if (exp < 10)
		nbexp[++i] = '0';
	ft_strdel(&nb);
	nb = ft_strjoin_free(nbexp, ft_itoa(exp), 0);
	nbexp = (sign) ? ft_strjoin_free("-\0", nb, 2) : ft_strdup_free(nb);
	return (nbexp);
}