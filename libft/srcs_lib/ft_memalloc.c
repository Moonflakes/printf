/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:41:11 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/20 15:28:06 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *ptr;

	if (!(ptr = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
