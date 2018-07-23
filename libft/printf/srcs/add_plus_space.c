/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plus_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:42:17 by mthiery           #+#    #+#             */
/*   Updated: 2018/04/23 18:42:20 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*add_plus_or_space(char *str, t_arg *arg, t_flags *flags, int num)
{
	int		i;
//	char	*types;

//	types = ft_strdup("idDgGfFeEaA");
	i = 0;
	if (flags->plus[num] == 1 && str[0] != '-')
	{
//		while (types[i])
//		{
//			if (arg->type[num] == types[i])
			if (ft_strchr("idDgGfFeEaA", arg->type[num]))
				str = ft_strjoin_free("+", str, 2);
//			i++;
//		}
	}
	if (flags->space[num] == 1 && str[0] != '-')
	{
//		while (types[i])
//		{
//			if (arg->type[num] == types[i])
			if (ft_strchr("idDgGfFeEaA", arg->type[num]))
				str = ft_strjoin_free(" ", str, 2);
//			i++;
//		}
	}
//	ft_strdel(&types);
	return (str);
}
