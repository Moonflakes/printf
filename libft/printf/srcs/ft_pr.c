/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:27:34 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:33:12 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*long long	pr_zero(long double g)
{
	long long i;

	i = 0;
	while (g > 0 && g < 1)
	{
		g = g * 10;
		i++;
	}
	return (i);
}*/

char		*ft_pr(long double g, t_flags *flags, t_g *val, char *nb)
{
//	if (g < 1 || flags->precision[val->num] == 0)
//	{
		nb = ft_strjoin_free(val->sign_nb,
		putg(nb_g(g, &val->exp, flags->precision[val->num], 1),
			ft_nblen(g * 1)), 0);
//	}
//	else
//	{
//		val->i = 0;
//		val->exp = 1;
//		g = ft_power_g(g, &val->i, &val->exp);
//		nb = ft_strjoin_free(val->sign_nb, pute(suppr_zero(process_nb(g, val->i,
//		flags->precision[val->num])), val->c, val->exp - 1, val->i), 0);
//	}
//	ft_putendl(nb);
	return (nb);
}
