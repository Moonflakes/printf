/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:34:45 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 09:45:50 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		extract_value(char *s, t_arg *arg, t_flags *flags, int num)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i] && !(s[i] > '0' && s[i] <= '9'))
	{
		if (arg->precision[num] == 0 && s[i] == '*')
			flags->asterix_w[num] = 1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	if (tmp)
		i = ft_atoi(tmp);
	else
		i = 0;
	ft_strdel(&tmp);
	return (i);
}
