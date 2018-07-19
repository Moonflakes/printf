/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:02:20 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:43:20 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*ft_convert(long double d, char *str, t_sign *sign)
{
	int i;

	i = 0;
	if (d == 0)
		str[i++] = '0';
	if (d == 1)
		str[i++] = '1';
	while (d > 0 && ((sign->ld == 0 && i < 15) || (sign->ld == 1 && i < 17)))
	{
		if (d == 1)
			break ;
		d = d * 16;
		sign->j = d;
		if (i == 0 && sign->ld == 0)
		{
			str[i++] = '1';
			str[i++] = '.';
		}
		if (i == 1 && sign->ld == 1)
			str[i++] = '.';
		str[i] = (sign->j > 9) ? sign->a + sign->j - 10 : sign->j + '0';
		d = d - sign->j;
		if (((sign->ld == 0 && i == 14) || (sign->ld == 1 && i == 16)) ||
				d <= 0)
			ft_round_hex(d, sign, &str[i]);
		i++;
	}
	str[i] = sign->a + 15;
	return (str);
}

int		ft_ft(int i, t_sign *sign, long long precision, char *str)
{
	if (i == 0 && sign->ld == 0)
	{
		str[i++] = (sign->d_zero == 0) ? '1' : '0';
		if (precision != 0)
			str[i++] = '.';
	}
	if (i == 1 && sign->ld == 1)
		str[i++] = '.';
	if (sign->j > 9)
		str[i] = sign->a + sign->j - 10;
	else
		str[i] = sign->j + '0';
	return (i);
}

char	*ft_convert_pr(long double d, char *str, t_sign *sign,
		long long precision)
{
	int i;

	i = 0;
	precision = (precision == 1) ? 0 : precision;
	if (d == 0)
		sign->d_zero = 1;
	while (i < precision + 1)
	{
		d = (d == 1) ? d : d * 16;
		sign->j =(d == 1) ? 0 : d;
		i = ft_ft(i, sign, precision, str);
		d = d - sign->j;
		if (precision == 0)
		{
			i--;
			sign->pr_z = 1;
			ft_round_hex(d, sign, &str[i++]);
		}
		if (i == precision)
			ft_round_hex(d, sign, &str[i]);
		if ((precision == 0 && sign->ld == 1) || (precision != 0 &&
			(sign->ld == 0 || sign->ld == 1)))
			i++;
	}
	str[i] = sign->a + 15;
	return (str);
}

char	*dtoa_base(long double d, t_sign *sign, int exp, long long precision)
{
	char	*str;
	int		j;

	if (d > 1)
		d = d - 1;
	if (d <= 0)
		j = 2;
	else
		j = 16;
	if (!(str = (char*)ft_memalloc(sizeof(char) * j + precision)))
		return (NULL);
	str[j + precision - 1] = '\0';
	if (sign->pr == 1)
		str = ft_convert_pr(d, str, sign, precision);
	else
		str = ft_convert(d, str, sign);
	if (sign->exp)
		str = if_nbneg(str, exp + sign->rnd, "", sign);
	else
		str = if_nbneg(str, exp + sign->rnd, "+", sign);
	return (str);
}
