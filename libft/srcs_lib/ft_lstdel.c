/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:09:49 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/10 15:10:18 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst && *alst)
	{
		while (*alst)
		{
			tmp = *alst;
			del((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(tmp);
		}
		*alst = NULL;
	}
}
