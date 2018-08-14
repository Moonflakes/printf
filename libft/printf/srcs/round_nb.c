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

char	*round_nb(char *n)
{
	int		j;
	char	*nb;

	nb = ft_strdup_free(n);
	j = ft_strlen(nb);
	if (nb[j - 1] > '5')
	{
		nb[j - 1] = '\0';
		j = ft_atoi(nb) + 1;
		ft_strdel(&nb);
		nb = ft_itoa(j);
	}
	else
		nb[j - 1] = '\0';
	n = ft_strdup_free(nb);
	return (n);
}

void	round_char_d(char **nb, int len)
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
    		round_char_d(nb, --len);
		}
    }
    else
    {
        nb[0][len - 1] = nb[0][len - 1] + 1;
	}
}

void	round_char_g(char **nb, int len, int *exp)
{
	char *tmp;
//	if (len - 1 <= 0)
//		return (0);
//	ft_putnbr(len - 1);
//	ft_putendl(" : len - 1");
//	ft_putstr(*nb);
//	ft_putendl(" : nb avant");
    if (nb[0][len - 1] == '9')
    {
        nb[0][len - 1] = '0';
		if (len - 1 == 0)
		{
		//	nb = ft_strjoin_free("1", nb, 2);
			tmp = ft_strjoin("1", *nb);
			ft_strdel(nb);
			*nb = ft_strdup(tmp);
			*exp += 1;
		}
//		ft_putstr(*nb);
//		ft_putendl(" : nb la");
        if (len - 1 > 0)
		{
//			ft_putnbr(len - 1);
//			ft_putendl(" : len - 1 before recall");
    		round_char_g(nb, --len, exp);
		}
    }
    else
    {
        nb[0][len - 1] = nb[0][len - 1] + 1;
	}
}
// a revoir pour 99999999

char	*round_g(char *n, int *exp)
{
	int		j;
	char	*nb;

	nb = ft_strdup_free(n);
//	ft_putendl(nb);
	j = ft_strlen(nb);
	if (j > 1)
	{
		if (nb[j - 1] >= '5')
		{
			nb[j - 1] = '\0';
//			j = ft_atoi(nb) + 1;
//			ft_strdel(&nb);
//			nb = ft_itoa(j);
//			ft_putendl("Call de roundchar.");
			round_char_g(&nb, j - 1, exp);
		}
		else
			nb[j - 1] = '\0';
//		ft_putendl(nb);
	}
	n = ft_strdup_free(nb);
//	ft_putstr(n);
//	ft_putendl(" : round");
	return (n);
}

char	*round_f(char *n)
{
	int		j;
	char	*nb;

	nb = ft_strdup_free(n);
//	ft_putendl(nb);
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
//		j = ft_atoi(nb) + 1;
//		ft_strdel(&nb);
//		nb = ft_itoa(j);
		round_char_d(&nb, j - 1);
//		ft_putendl(nb);
	}
	else
		nb[j - 1] = '\0';
	n = ft_strdup_free(nb);
	return (n);
}

char	*round_e(long long i, char *n)
{
	int		j;
	char	*nb;

	nb = ft_strdup_free(n);
//	ft_putstr(nb);
//	ft_putendl(" : nb rde");
	j = ft_strlen(nb);
	if ((nb[j - 2] <= '5' && nb[j - 1] >= '5') ||
		(nb[j - 2] > '5' && nb[j - 1] > '5') || (i == 1 && nb[j - 1] >= '5'))
	{
		nb[j - 1] = '\0';
//		j = ft_atoi(nb) + 1;
//		ft_strdel(&nb);
//		nb = ft_itoa(j);
		round_char_d(&nb, j - 1);
	}
	else
		nb[j - 1] = '\0';
	n = ft_strdup_free(nb);
//	ft_putendl(n);
	return (n);
}
