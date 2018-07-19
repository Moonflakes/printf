/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:52:24 by mthiery           #+#    #+#             */
/*   Updated: 2018/01/11 14:52:27 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	char *str;

	str = ft_strsub(s, start, len);
	ft_strdel(&s);
	return (str);
}
