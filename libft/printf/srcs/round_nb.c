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