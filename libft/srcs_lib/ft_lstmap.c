/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:12:16 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 17:38:49 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
	t_list *bb;

	if (lst && f)
	{
		tmp = f(lst);
		bb = tmp;
		new = bb;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			bb->next = tmp;
			bb = bb->next;
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
