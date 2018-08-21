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

#include "printf.h"

char	*add_plus_or_space(char *str, t_arg *arg, t_flags *flags, int num)
{
	int		i;

	i = 0;
	if (flags->plus[num] == 1 && str[0] != '-')
		if (ft_strchr("idDgGfFeEaA", arg->type[num]))
			str = ft_strjoin_free("+", str, 2);
	if (flags->space[num] == 1 && str[0] != '-')
		if (ft_strchr("idDgGfFeEaA", arg->type[num]))
			str = ft_strjoin_free(" ", str, 2);
	return (str);
}
