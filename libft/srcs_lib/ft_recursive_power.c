/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 08:25:08 by mthiery           #+#    #+#             */
/*   Updated: 2017/11/21 19:01:22 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_recursive_power(long long nb, long long power)
{
	if (power < 0)
		return (0);
	if (power == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_power(nb, (power - 1)));
}
