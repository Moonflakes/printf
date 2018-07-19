/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:38:12 by mthiery           #+#    #+#             */
/*   Updated: 2018/04/19 17:38:16 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

long long	btoi(char *octet)
{
	long long	i;
	long long	j;
	long long	nb;
	int			u;

	i = 0;
	nb = 0;
	j = 7;
	while (octet && octet[i] && j >= 0)
	{
		u = (octet[i] == '1') ? 1 : 0;
		nb = nb + (u * ft_iterative_power(2, j));
		j--;
		i++;
	}
//	ft_putnbr(nb);
//	ft_putendl(" : nb");
	return (nb);
}

void		octect_zero(int i, char *b, char **octet, int nb_octet)
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
		if (!(octet[k] = (char*)ft_memalloc(sizeof(char) * 9)))
			return ;
		octet[k][8] = '\0';
		if (k == 0)
		{
			octect_zero(i, b, octet, nb_octet);
			return ;
		}
		else
		{
			ft_strdel(&octet[k]);
			octet[k] = ft_strjoin("10", &b[i - 6]);
			b[i - 6] = '\0';
			i = i - 6;
			return ;
		}
	}
}

char		**split_octet(char *b, long long nb)
{
	char	**octet;
	int		nb_octet;
	int		k;

	nb_octet = (nbase_len(nb, 2) / 6) + 1;
	k = nb_octet - 1;
	if (!(octet = (char**)ft_memalloc(sizeof(char*) * (nb_octet + 1))))
		return (NULL);
	while (k >= 0)
	{
//		ft_putendl("while");
		octet_process(k, octet, b, nb_octet);
		k--;
	}
	ft_strdel(&b);
	return (octet);
}

char		*printable_w(long long w, t_arg *arg)
{
	int		nb_octet;
	char	**octet;
	char	*str;
	int		i;

	nb_octet = (nbase_len(w, 2) / 6) + 1;
//	ft_putnbr(w);
//	ft_putendl(" : w");
//	ft_putnbr(nb_octet);
//	ft_putendl(" : nb_octet");
//	ft_putnbr(MB_LEN_MAX);
//	ft_putendl(" : MB_LEN_MAX");
	str = NULL;
	if (w <= 127 && w >= 0)
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * 2)))
			return (0);
		str[0] = w;
		str[1] = '\0';
//		ft_putstr(str);
 	}
	else
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * (nb_octet * 8))))
			return (0);
		octet = split_octet(ft_itoabase(w, 2), w);
		i = 0;
		arg->ret = 0;
		while (octet[i])
		{
//			ft_putendl("lala");
//			ft_putendl(octet[i]);
/*			if (btoi(octet[i]) < 256)
			{
				arg->ret = -1;
				return (ft_strdup(""));
			}*/
			str[i] = (char)btoi(octet[i]);
//			ft_putendl("lolo");
			ft_strdel(&octet[i]);
//			ft_putendl("lili");
			i++;
		}
		str[i] = '\0';
//		ft_putstr(str);
//		ft_putnbr(mblen(str, MB_CUR_MAX));
//		ft_putendl(" : mblen");
		free((void*)octet);
	}
	return (str);
}

	