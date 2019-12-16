/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_octet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:38:12 by mthiery           #+#    #+#             */
/*   Updated: 2018/04/19 17:38:16 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	btoi(char *octet)
{
	long long	i;
	long long	j;
	long long	nb;
	int			u;

	i = 0;
	nb = 0;
	j = 7;
	while (octet && octet[i] != '\0' && j >= 0)
	{
		u = (octet[i] == '1') ? 1 : 0;
		nb = nb + (u * ft_iterative_power(2, j));
		j--;
		i++;
	}
	return (nb);
}

void		octet_zero(int i, char *b, char **octet, int nb_octet)
{
	int j;
	int l;

	j = 8;
	l = 8 - i;
	i--;
	while (j-- >= 0)
	{
		if (i >= 0)
			octet[0][j] = b[i];
		else
		{
			while (l - nb_octet > 0)
			{
				octet[0][j--] = '0';
				l--;
			}
			while (l >= 0)
			{
				octet[0][j--] = '1';
				l--;
			}
		}
		i--;
	}
}

void		octet_process(int k, char **octet, char *b, int nb_octet)
{
	int i;

	i = ft_strlen(b);
	while (i >= 0)
	{
		if (k == 0)
		{
			if (!(octet[k] = (char*)ft_memalloc(sizeof(char) * 9)))
				return ;
			octet_zero(i, b, octet, nb_octet);
			return ;
		}
		else if (k > 0)
		{
			octet[k] = ft_strjoin("10", &b[i - 6]);
			b[i - 6] = '\0';
			i = i - 6;
			return ;
		}
	}
}

char		**split_octet(char *b)
{
	char	**octet;
	int		nb_octet;
	int		k;

	nb_octet = (ft_strlen(b) / 6) + 1;
	k = nb_octet - 1;
	if (!(octet = (char**)ft_memalloc(sizeof(char*) * (nb_octet + 2))))
		return (NULL);
	octet[nb_octet] = NULL;
	while (k >= 0)
	{
		octet_process(k, octet, b, nb_octet);
		k--;
	}
	ft_strdel(&b);
	return (octet);
}

void		octet_to_str(t_arg *arg, char *str, int nb_octet, long long w)
{
	char	**octet;
	int		i;

	octet = split_octet(ft_uitoabase(w, 2));
	i = 0;
	arg->ret = 0;
	while (octet[i] && i < nb_octet)
	{
		str[i] = (char)btoi(octet[i]);
		i++;
	}
	str[i] = '\0';
	i = -1;
	while (octet[++i])
		ft_strdel(&octet[i]);
	free((void*)octet);
}
