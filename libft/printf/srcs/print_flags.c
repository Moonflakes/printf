/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 09:47:15 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 10:51:11 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	begin_str(char **padstr, t_flags *flags, t_int *inc, t_arg *arg)
{
	if ((inc->str[inc->j] == '-' || inc->str[inc->j] == '+' ||
		inc->str[inc->j] == ' ')
		&& (arg->type[inc->num] != 's' || arg->type[inc->num] != 'S'))
	{
		if (flags->zero[inc->num] == 1)
			padstr[0][inc->a++] = inc->str[inc->j++];
	}
	if (flags->zero[inc->num] == 1 && flags->htag[inc->num] == 1 &&
		((ft_strchr("pxX", arg->type[inc->num]) && arg->precision[inc->num] == 0) ||
		(ft_strchr("aA", arg->type[inc->num]) && arg->precision[inc->num] == 1)))
	{
		while (inc->str[inc->j])
		{
			padstr[0][inc->a++] = inc->str[inc->j];
			if (inc->str[inc->j] == 'x' || inc->str[inc->j] == 'X')
			{
				inc->j++;
				break ;
			}
			inc->j++;
		}
	}
}

char	*put_pad_l(char **padstr, t_arg *arg, t_flags *flags, t_int *inc)
{
	unsigned long	k;
	char			pad;
	int				len;

	k = 0;
	len = ft_strlen(inc->str);
//	ft_putnbr(arg->precision[inc->num]);
//	ft_putendl(" : arg pr");
//	ft_putnbr(len);
//	ft_putendl(" : len");
	pad = ((ft_strchr("%aAgGfFeE", arg->type[inc->num]) && flags->zero[inc->num] == 1) ||
			(!ft_strchr("sScCp", arg->type[inc->num]) && ft_strchr("idDuUoOxXb", arg->type[inc->num])
			&& flags->zero[inc->num] == 1 && arg->precision[inc->num] == 0)) ? '0' : ' ';
	while (inc->str[inc->j] || (len == 0 && (arg->type[inc->num] == 'S' ||
		(arg->type[inc->num] == 's' && arg->length[inc->num] == 1))))
	{
		begin_str(&padstr[0], flags, inc, arg);
		while (k < (flags->width[inc->num] - len))
		{
			padstr[0][inc->a++] = pad;
			k++;
		}
		padstr[0][inc->a++] = inc->str[inc->j++];
		if (len == 0)
			len = 1;
	}
	if (!inc->str || !inc->str[0])
	{
		while (k < (flags->width[inc->num] - len))
		{
			padstr[0][inc->a++] = pad;
			k++;
		}
	}
	return (ft_strdup_free(padstr[0]));
}

char	*put_pad_r(char **padstr, t_arg *arg, t_flags *flags, t_int *inc)
{
	unsigned long	k;
	char			pad;

	k = (inc->str[0] == '\0'/* && inc->str[1] == 0 */&& arg->type[inc->num] != 's') ? 1 : 0;
	pad = ' ';
	while (inc->str[inc->j])
	{
		padstr[0][inc->a++] = inc->str[inc->j++];
	}
	while (k < (flags->width[inc->num] - ft_strlen(inc->str)))
	{
		padstr[0][inc->a++] = pad;
		k++;
	}
	return (ft_strdup_free(padstr[0]));
}

char	*padding(char *str, t_arg *arg, t_flags *flags, int num)
{
	int		i;
	int		j;
	char	*padstr;
	t_int	inc;

	ft_bzero(&inc, sizeof(t_int));
	inc = (t_int){0, 0, num, ft_strdup(str)};
	padstr = NULL;
	i = 0;
	if (flags->width[num] > ft_strlen(str))
	{
		j = ft_strlen(str) + (flags->width[num] - ft_strlen(str));
		if (!(padstr = (char*)ft_memalloc(sizeof(char) * j + 1)))
		{
			ft_strdel(&inc.str);
			return (NULL);
		}
		padstr[j] = '\0';
		ft_strdel(&str);
		if (flags->left[num])
			str = put_pad_r(&padstr, arg, flags, &inc);
		else
			str = put_pad_l(&padstr, arg, flags, &inc);
	}
	ft_strdel(&inc.str);
	return (str);
}

char	*process_flags(char *str, t_arg *arg, t_flags *flags, int num)
{
	
	str = htag_process(str, arg, flags, num);
	str = add_plus_or_space(str, arg, flags, num);
	str = padding(str, arg, flags, num);
	return (str);
}
