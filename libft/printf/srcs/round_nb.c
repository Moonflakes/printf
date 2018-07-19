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

#include "../includes/printf.h"

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
char    *round_char_d(char *nb, int len)
{
    if (nb[len - 1] == '9')
    {
        nb[len - 1] = '0';
        if (len - 1 > 0)
            round_char_d(nb, len - 1);
    }
    else
    {
        nb[len - 1] = nb[len - 1] + 1;
    }
    return (nb);
}

char	*round_g(char *n)
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
			nb = round_char_d(nb, j - 1);
//			ft_putendl(nb);
		}
		else
			nb[j - 1] = '\0';
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
		nb = round_char_d(nb, j - 1);
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
//	ft_putendl(nb);
	j = ft_strlen(nb);
	if ((nb[j - 2] <= '5' && nb[j - 1] >= '5') ||
		(nb[j - 2] > '5' && nb[j - 1] > '5') || (i == 1 && nb[j - 1] >= '5'))
	{
		nb[j - 1] = '\0';
//		j = ft_atoi(nb) + 1;
//		ft_strdel(&nb);
//		nb = ft_itoa(j);
		nb = round_char_d(nb, j - 1);
	}
	else
		nb[j - 1] = '\0';
	n = ft_strdup_free(nb);
//	ft_putendl(n);
	return (n);
}
