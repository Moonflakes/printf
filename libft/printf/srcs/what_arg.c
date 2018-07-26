/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:16:25 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 14:16:44 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		nb_prct(const char *format)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i + 1] == '%')
				i++;
			num++;
		}
		if (format[i] == '*')
			num++;
		i++;
	}
//	ft_putnbr(num);
//	ft_putendl(" : nb %");
	return (num);
}

int		len_and_type(const char *s, t_arg *arg, int num, t_flags *flags)
{
	int		i;
	int		j;
	char	*type;

	type = NULL;
	if (!(type = ft_strdup("cCdDioOuUbxXeEfFgGaAnpsSrk")))
		return (0);
	i = -1;
	while (s[++i])
	{
		j = -1;
//		ft_putchar('\n');
//		ft_putchar(s[i]);
		while (type[++j])
		{
//			ft_putchar(type[j]);
			if (s[i] == type[j])
			{
//				ft_putendl("je passe la");
				arg->type[num] = type[j];
			}
		}
		if (s[i] == '%' && arg->type)
			arg->type[num] = '%';
		if (arg->type && arg->type[num])
		{
//			ft_putendl("je passe ici");
			arg->size[num] = i + 1;
			arg->strp[num] = ft_strndup(s, arg->size[num]);
//			ft_putendl("");
//			ft_putstr(arg->strp[num]);
//			ft_putendl(" : strp");
			process_strp(arg, num, flags);
			ft_strdel(&type);
			return (i + 1);
		}
	}
	ft_strdel(&type);
	return (0);
}

void	set_nb_arg(t_arg *arg, t_flags *flags)
{
	int i;

	i = 0;
	while (i < arg->nb_prct)
	{
	//	if (flags->index_arg[i] >= flags->index_arg[i + 1])
			arg->nb_arg = flags->index_arg[i] + 1;
		i++;
	}
	
}

void	set_index_arg(t_arg *arg, t_flags *flags)
{
	int i;

	i = 0;
	if (arg->dollar == 1)
	{
		while (i < arg->nb_prct)
		{
			if (flags->index_arg[i - 1] && flags->index_arg[i] == 0
				&& flags->index_arg[i - 1] != 0)
				flags->index_arg[i] = flags->index_arg[i - 1] + 1;
			i++;
		}
	}
	else
	{
		while (i < arg->nb_prct)
		{
			flags->index_arg[i] = i;
			i++;
		}
	}
	set_nb_arg(arg, flags);
}

void	num_arg(const char *format, t_arg *arg, t_flags *flags)
{
	size_t	i;
	int		num;

	i = 0;
	num = -1;
	while (i < ft_strlen(format))
	{
		while (format[i] && format[i] != '%')
			i++;
		if (format[i] && format[i] == '%' && format[i + 1])
		{
			num++;
		}
		if (format[i] && num > -1)
			i = i + len_and_type(format + i + 1, arg, num, flags);
		i++;
	}
	arg->nb_prct = num + 1;
//	ft_putnbr(arg->nb_prct);
//	ft_putendl(" : nb_prct");
	set_index_arg(arg, flags);
}
