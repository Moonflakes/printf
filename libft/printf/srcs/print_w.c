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

#include "printf.h"

char		*printable_w(long long w, t_arg *arg)
{
	int		nb_octet;
	char	*str;

	nb_octet = (nbase_len(w, 2) / 6) + 1;
	str = NULL;
	if (w <= 127 && w >= 0)
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * 2)))
			return (0);
		str[0] = w;
		str[1] = '\0';
	}
	else
	{
		if (!(str = (char*)ft_memalloc(sizeof(char) * (nb_octet * 8))))
			return (0);
		octet_to_str(arg, str, nb_octet, w);
	}
	return (str);
}
