/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:06:09 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:36:45 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../../includes/libft.h"
# include "stdarg.h"
# include <stdio.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>

int **n;

typedef struct			s_arg
{
	int					nb_arg;
	int					nb_prct;
	int					ret;
	char				*type;
	size_t				*size;
	char				**strp;
	int					*length;
	long long			*i;
	unsigned long long	*ull;
	long double 		*d;
	int					**s;
	int					dollar;
	int					*precision;
}						t_arg;

typedef struct			s_flags
{
	int					prpass;
	int					*htag;
	int					*zero;
	int					*left;
	int					*plus;
	int					*space;
	int					*asterix_p;
	int					*asterix_w;
	int					*cote;
	int					*dollar;
	int					*index_arg;
	int					*precision;
	size_t				*width;
}						t_flags;

typedef	struct			s_int
{
	int					j;
	int					a;
	int					num;
	char				*str;
}						t_int;

typedef struct			s_sign
{
	int					nb;
	int					rnd;
	int					exp;
	int					ld;
	int					pr;
	int					pr_z;
	int					j;
	char				a;
	int					d_zero;
}						t_sign;

typedef struct			s_tf
{
	char				*cond1;
	int					cond2;
	int					(*f1)(t_arg *arg, t_flags *flags, int num);
	int					(*f2)(char c, t_arg *arg, t_flags *flags, int num);
}						t_tf;

int						ft_printf(const char *format, ...);
void					stock_arg(va_list ap, t_arg *arg, t_flags *flags);
int						print_arg(t_arg *arg, t_flags *flags, int num);
int						printing(char **str, t_arg *arg, t_flags *flags, int num);
void					verif_next_arg(t_arg *arg, t_flags *flags, int next);

int						*int_tab_malloc(int len);
long long				*ll_tab_malloc(int len);
unsigned long long		*ull_tab_malloc(int len);
char					*char_tab_malloc(int len);
size_t					*size_t_tab_malloc(int len);
char					**str_tab_malloc(int len);
int						**long_tab_malloc(int len);
long double				*dbl_tab_malloc(int len);

void					init_struct_arg(t_arg *arg, int len);
void					init_struct_flags(t_flags *flags, int len);

void					free_struct(t_arg *arg, t_flags *flags);
void					free_t_int(t_int *inc);

void					init_flags(t_arg *arg, int i, t_flags *flags, int num);

int						print_char(t_arg *arg, t_flags *flags, int num);
char					*printable_w(long long w, t_arg *arg);
int						print_string(t_arg *arg, t_flags *flags, int num);
int						print_nb(t_arg *arg, t_flags *flags, int num);
int						print_base(char base, t_arg *arg, t_flags *flags, int num);
int						print_hex(char c, t_arg *arg, t_flags *flags, int num);
int						print_f(t_arg *arg, t_flags *flags, int num);
int						print_e(char c, t_arg *arg, t_flags *flags, int num);
int						print_g(char c, t_arg *arg, t_flags *flags, int num);
int						print_a(char a, t_arg *arg, t_flags *flags, int num);
int						print_la(char a, t_arg *arg, t_flags *flags, int num);
int						print_p(t_arg *arg, t_flags *flags, int num);
int						if_length(t_arg *arg, t_flags *flags, int num);

char					*process_flags(char *str, t_arg *arg, t_flags *flags, int num);
char					*htag_process(char *str, t_arg *arg, t_flags *flags, int num);
char					*add_plus_or_space(char *str, t_arg *arg, t_flags *flags,
						int num);
int						ft_color(const char *format, int i);

void					num_arg(const char *format, t_arg *arg, t_flags *flags);
int						nb_prct(const char *format);
int						len_and_type(const char *s, t_arg *arg, int num,
						t_flags *flags);
int						extract_value(char *s, t_arg *arg, t_flags *flags, int num);
void					width(t_arg *arg, t_flags *flags, int num);
void					process_strp(t_arg *arg, int num, t_flags *flags);
char					*char_tab_malloc(int len);

void					ft_round_hex(double d, t_sign *sign, char *str);
char					*if_nbneg(char *str, int exp, char *signe, t_sign *sign);
char					*dtoa_base(long double d, t_sign *sign, int exp,
						long long precision);
char					*if_maj(char *str, char a);

/*
** UTILS DOUBLE
*/
char					*char_d(long double d, int precision, int *sign_point, int exp);
void 					insert_point_sign_d(int place_point, char **nb, int *sign_point);
int						round_dbl(long double d, char **nb, int len, int precision);
int						exposant_d(long double d);
char					*add_zero_d(char *nb, int *exp, int *pr);
char					*suppr_zero(char *nb);
int						suppr_zero_g(char **nb);
char					*insert_point_sign(char *nb, int exp, int *sign_point, int d);
char					*add_exp(char *nb, int exp, char e, int sign);
int						abs_value(int value);
char					*round_d(char *nb, int *exp, int d);
char					*round_hex(char *hex);
int		reset_nb(char **nb, int i, int precision, int len);

#endif
