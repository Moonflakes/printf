/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:19:24 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 10:38:54 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*pr_str(char *str, t_flags *flags, t_arg *arg, int num)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	if (flags->precision[num] < i && arg->precision[num] == 1)
	{
		while (j < flags->precision[num])
		{
			j++;
		}
		str[j] = '\0';
	}
	if (mblen(str, MB_CUR_MAX) == -1)
		str = ft_strdup_del("", str);
	return (str);
}

char	*delstr(char **c, char **str, t_arg *arg)
{
	ft_strdel(c);
	ft_strdel(str);
	arg->ret = -1;
	return (ft_strdup(""));
}

char	*blabla(t_arg *arg, t_flags *flags, int i, int num)
{
	char	*c;
	int		nb_octet;
	int		*w_str;
	char	*str;

	setlocale(LC_ALL, "");
	w_str = arg->s[flags->index_arg[num]];
	if (w_str[0])
		str = ft_strdup_free(printable_w(w_str[0], arg));
	nb_octet = (w_str[0] <= 127 && w_str[0] >= 0) ? 1 :
		(nbase_len(w_str[0], 2) / 6) + 1;
	while (w_str[++i])
	{
		nb_octet = nb_octet + (nbase_len(w_str[i], 2) / 6) + 1;
		if ((nb_octet <= flags->precision[num] && arg->precision[num] == 1)
			|| arg->precision[num] == 0)
		{
			c = ft_strdup_free(printable_w(w_str[i], arg));
			if (mblen(c, MB_CUR_MAX) == -1)
				return (delstr(&c, &str, arg));
			str = ft_strjoin_free(str, c, 0);
		}
	}
	return (str);
}

int		print_string(t_arg *arg, t_flags *flags, int num)
{
	char	*str;
	int		*w_str;

	w_str = arg->s[flags->index_arg[num]];
	if ((int)w_str >= 0 && (int)w_str <= 127 && (arg->type[num] == 'S'
		|| (arg->type[num] == 's' && arg->length[num] == 1)))
	{
		str = ft_memalloc(sizeof(char) * (2));
		str[0] = (int)w_str;
	}
	else if (arg->s[flags->index_arg[num]] == NULL)
		str = ft_strdup("(null)");
	else if (w_str[0] == 0)
		str = ft_strdup("");
	else if (arg->type[num] == 's' && arg->length[num] == 0
			&& arg->s[flags->index_arg[num]] != NULL)
		str = ft_strdup((char*)arg->s[flags->index_arg[num]]);
	else
	{
		str = (blabla(arg, flags, 0, num));
		if (arg->ret == -1)
			return (printing(&str, arg, flags, num));
	}
	str = pr_str(str, flags, arg, num);
	return (printing(&str, arg, flags, num));
}
