/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:19:24 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 10:38:54 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "funct.h"

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

void	verif_next_arg(t_arg *arg, t_flags *flags, int next)
{
	char *sw_next;
//	ft_putendl("je vais la");
	if (arg->i && arg->i[flags->index_arg[next]])
	{
//		ft_putendl("kikou");
		if ((arg->type[next] == 'C' || (arg->type[next] == 'c'
			&& arg->length[next] == 1)) && !(arg->i[flags->index_arg[next]]
			<= 127 && arg->i[flags->index_arg[next]] >= 0))
		{
//			ft_putendl("lala");
			sw_next = printable_w(arg->i[flags->index_arg[next]], arg);
			if (mblen(sw_next, MB_CUR_MAX) == -1)
				arg->ret = -1;
			ft_strdel(&sw_next);
//			ft_putendl("loulou");
		}
	}
//	ft_putendl("je ne passe pas");
}

int	print_char(t_arg *arg, t_flags *flags, int num)
{
	char c;
	char *str;
//	mbstate_t ps;

	c = arg->i[flags->index_arg[num]];
//	ft_putnbr(arg->i[flags->index_arg[num]]);
//	ft_putendl(" : i");
	setlocale(LC_ALL, "");
	if ((arg->type[num] == 'c' && arg->length[num] == 0) ||
		(arg->i[flags->index_arg[num]] <= 127 &&
		arg->i[flags->index_arg[num]] >= 0))
		str = ft_strndup(&c, 1);
	else
	{
		str = printable_w(arg->i[flags->index_arg[num]], arg);
		if (mblen(str, MB_CUR_MAX) == -1)
			arg->ret = -1;
	}
//	ft_putnbr(mbrlen(str, MB_CUR_MAX, &ps));
//	ft_putnbr(mblen(str, MB_CUR_MAX));
//	ft_putendl(" : mblen");
	return (printing(&str, arg, flags, num));
}

int ft_tabnblen(int *tabnb)
{
	int i;

	i = 0;
	while (tabnb[i])
	{
		i++;
	}
	return (i);
}

int	print_string(t_arg *arg, t_flags *flags, int num)
{
	char	*str;
	int		*w_str;
	int		i;
	int		nb_octet;
	char	*c;

	i = 0;
	w_str = arg->s[flags->index_arg[num]];
//	ft_putnbr((int)w_str);
//	ft_putendl("");
//	ft_putendl("lili");
//	ft_putnbr(arg->s[flags->index_arg[num]][0]);
//	ft_putendl(" : arg->s");
//	ft_putnbr(w_str[0]);
//	ft_putendl(" : w1");
	setlocale(LC_ALL, "");
	if ((int)w_str >= 0 && (int)w_str <= 127 && (arg->type[num] == 'S'
		|| (arg->type[num] == 's' && arg->length[num] == 1)))
	{
//		ft_putendl("jiji");
		str = ft_memalloc(sizeof(char) * (2));
		str[0] = (int)w_str;
//		str[0] = *w_str + '0';
	}
	else if (arg->s[flags->index_arg[num]] == NULL)
		str = ft_strdup("(null)");
	else if (w_str[0] == 0)
		str = ft_strdup("");
	else if (arg->type[num] == 's' && arg->length[num] == 0
			&& arg->s[flags->index_arg[num]] != NULL)
	{
		str = ft_strdup((char*)arg->s[flags->index_arg[num]]);
//		ft_putendl("mama");
	}
	else
	{
//		ft_putendl("lala");
		if (w_str[i])
		{
//			ft_putendl("moumou");
//			ft_strdel(str);
			str = ft_strdup_free(printable_w(w_str[i], arg));
		}
//		ft_putnbr(mblen(str, MB_CUR_MAX));
//		ft_putendl(" : mblen");
		if (w_str[i] <= 127 && w_str[i] >= 0)
			nb_octet = 1;
		else
			nb_octet = (nbase_len(w_str[i], 2) / 6) + 1;
		i++;
		while (w_str[i])
		{
//			ft_putendl("");
//			ft_putstr(str);
//			ft_putendl(" : str cur");
//			ft_putnbr(ft_strlen(str));
//			ft_putendl(" : strlen cur");
//			ft_putnbr(flags->precision[num]);
//			ft_putendl(" : precision");
//			ft_putnbr(arg->precision[num]);
//			ft_putendl(" : precision");
			nb_octet = nb_octet + (nbase_len(w_str[i], 2) / 6) + 1;
//			ft_putnbr(nb_octet);
//			ft_putendl(" : nb_octet");
			if ((nb_octet <= flags->precision[num] && arg->precision[num] == 1)
				|| arg->precision[num] == 0)
			{
				c = ft_strdup_free(printable_w(w_str[i], arg));
				if (mblen(c, MB_CUR_MAX) == -1)
				{
					ft_strdel(&c);
					ft_strdel(&str);
					str = ft_strdup("");
					arg->ret = -1;
					return (printing(&str, arg, flags, num));
				}
				str = ft_strjoin_free(str, c, 0);
			}
			i++;
		}
	}
	str = pr_str(str, flags, arg, num);
	return (printing(&str, arg, flags, num));
}

int	what_base(t_arg *arg, int num)
{
//	ft_putendl("je passe la");
	if (arg->type[num] == 'u' || arg->type[num] == 'U')
		return (10);
	if (arg->type[num] == 'o' || arg->type[num] == 'O')
		return (8);
	if (arg->type[num] == 'b')
		return (2);
	return (0);
}

int	if_length(t_arg *arg, t_flags *flags, int num)
{
	if (arg->length[num] == 1)
		return (print_la(arg->type[num], arg, flags, num));
	else
		return (print_a(arg->type[num], arg, flags, num));
	return (0);
}

int	print_arg(t_arg *arg, t_flags *flags, int num)
{
	char	*pct;
	int		i;

	i = 0;
	if (arg->type)
	{
		if (arg->type[num] == 'u' || arg->type[num] == 'U' || arg->type[num] == 'o'
			|| arg->type[num] == 'O' || arg->type[num] == 'b')
			return (print_base(what_base(arg, num), arg, flags, num));
		else if (arg->type[num] == 'x' || arg->type[num] == 'X')
			return (print_hex(arg->type[num], arg, flags, num));
		else if (arg->type[num] == 'e' || arg->type[num] == 'E')
			return (print_e(arg->type[num], arg, flags, num));
		else if (arg->type[num] == 'g' || arg->type[num] == 'G')
			return (print_g(arg->type[num], arg, flags, num));
		else if (arg->type[num] == '%')
		{
			pct = ft_strdup("%");
			return(printing(&pct, arg, flags, num));
		}
		while (tabf[i].cond && !ft_strchr(tabf[i].cond, arg->type[num]))
			++i;
		return (tabf[i].f(arg, flags, num));
	}
	return (0);
}
