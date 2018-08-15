/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:38:17 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:39:57 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	round_char_f(char **nb, int len)
{
	char *tmp;
//	if (len - 1 <= 0)
//		return (0);
//	ft_putnbr(len - 1);
//	ft_putendl(" : len - 1");
    if (nb[0][len - 1] == '9')
    {
        nb[0][len - 1] = '0';
		if (len - 1 == 0)
		{
		//	nb = ft_strjoin_free("1", nb, 2);
			tmp = ft_strjoin("1", *nb);
			ft_strdel(nb);
			*nb = ft_strdup(tmp);
		}
//		ft_putstr(*nb);
//		ft_putendl(" : nb la");
        if (len - 1 > 0)
		{
//			ft_putnbr(len - 1);
//			ft_putendl(" : len - 1 before recall");
    		round_char_f(nb, --len);
		}
    }
    else
    {
        nb[0][len - 1] = nb[0][len - 1] + 1;
	}
}

void	round_char_d(char **nb, int len, int *exp, int d)
{
	char *tmp;
    if (nb[0][len - 1] == '9')
    {
        nb[0][len - 1] = '0';
		if (len - 1 == 0)
		{
			if (d)
			{
				tmp = ft_strjoin("1", *nb);
				ft_strdel(nb);
				*nb = ft_strdup(tmp);
			}
			else
				nb[0][len - 1] = '1';
			*exp += 1;
		}
        if (len - 1 > 0)
    		round_char_d(nb, --len, exp, d);
    }
    else
        nb[0][len - 1] = nb[0][len - 1] + 1;
}

char	*round_d(char *n, int *exp, int d)
{
	int		j;
	char	*nb;

	nb = ft_strdup_free(n);
	j = ft_strlen(nb);
	if (j > 1)
	{
		if (nb[j - 1] >= '5')
		{
			nb[j - 1] = '\0';
			round_char_d(&nb, j - 1, exp, d);
		}
		else
			nb[j - 1] = '\0';
	}
	n = ft_strdup_free(nb);
	return (n);
}

char	*round_f(char *n)
{
	int		j;
	char	*nb;

	nb = ft_strdup_free(n);
	j = ft_strlen(nb);
	if (j == 1 && nb[0] == '0')
	{
		ft_strdel(&nb);
		nb = ft_strdup("0");
	}
	else if ((nb[0] == '0' && nb[j - 1] > '5') ||
			(nb[0] != '0' && nb[j - 1] >= '5'))
	{
		nb[j - 1] = '\0';
		round_char_f(&nb, j - 1);
	}
	else
		nb[j - 1] = '\0';
	n = ft_strdup_free(nb);
	return (n);
}
