/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:56:46 by mthiery           #+#    #+#             */
/*   Updated: 2018/04/23 14:56:52 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_mode(const char *format)
{
	char *mode;

	if (format[0] == 'b')
		mode = ft_strdup("\x1b[1m");
	else if (format[0] == 'd')
		mode = ft_strdup("\x1b[2m");
	else if (format[0] == 'u')
		mode = ft_strdup("\x1b[4m");
	else if (format[0] == 'c')
		mode = ft_strdup("\x1b[5m");
	else if (format[0] == 'r')
		mode = ft_strdup("\x1b[7m");
	else if (format[0] == 'h')
		mode = ft_strdup("\x1b[8m");
	else
		mode = NULL;
	if (mode || format[0] == '_')
	{
		ft_putstr(mode);
		free(mode);
		return (1);
	}
	return (0);
}

int		util_bg(char *backgroud, const char *format)
{
	if ((backgroud && ft_mode(&format[1])) ||
	(format[0] == '_' && ft_mode(&format[1])))
	{
		ft_putstr(backgroud);
		ft_strdel(&backgroud);
		return (ft_mode(&format[1]));
	}
	return (0);
}

int		ft_backgroud(const char *format)
{
	char *backgroud;

	backgroud = NULL;
	if (format[0] == 'R')
		backgroud = ft_strdup("\x1b[41m");
	else if (format[0] == 'G')
		backgroud = ft_strdup("\x1b[42m");
	else if (format[0] == 'Y')
		backgroud = ft_strdup("\x1b[43m");
	else if (format[0] == 'B')
		backgroud = ft_strdup("\x1b[44m");
	else if (format[0] == 'M')
		backgroud = ft_strdup("\x1b[45m");
	else if (format[0] == 'C')
		backgroud = ft_strdup("\x1b[46m");
	else if (format[0] == 'W')
		backgroud = ft_strdup("\x1b[47m");
	else if (format[0] == 'N')
		backgroud = ft_strdup("\x1b[40m");
	return (util_bg(backgroud, format));
}

char	*util_ink(const char *format, char *color)
{
	if (format[0] == 'r')
		color = ft_strdup("\x1b[31m");
	else if (format[0] == 'g')
		color = ft_strdup("\x1b[32m");
	else if (format[0] == 'y')
		color = ft_strdup("\x1b[33m");
	else if (format[0] == 'b')
		color = ft_strdup("\x1b[34m");
	else if (format[0] == 'm')
		color = ft_strdup("\x1b[35m");
	else if (format[0] == 'c')
		color = ft_strdup("\x1b[36m");
	else if (format[0] == 'w')
		color = ft_strdup("\x1b[37m");
	else if (format[0] == 'n')
		color = ft_strdup("\x1b[30m");
	else if (format[0] == 'd')
		color = ft_strdup("\x1b[0m");
	return (color);
}

int		ft_color(const char *format, int i)
{
	char *color;

	color = NULL;
	if (format[0] == '{' && format[4] == '}')
	{
		color = util_ink(&format[1], color);
		if ((color && ft_backgroud(&format[2])) ||
		(format[1] == '_' && ft_backgroud(&format[2])))
		{
			ft_putstr(color);
			ft_strdel(&color);
			ft_backgroud(&format[2]);
			return (i + 5);
		}
	}
	return (i);
}
