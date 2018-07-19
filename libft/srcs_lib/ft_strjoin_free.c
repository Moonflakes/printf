/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:53:05 by mthiery           #+#    #+#             */
/*   Updated: 2018/01/08 13:41:08 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int i)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (i == 0 || i == 1)
		ft_strdel(&s1);
	if (i == 0 || i == 2)
		ft_strdel(&s2);
	return (str);
}
