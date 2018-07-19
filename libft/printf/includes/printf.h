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
# include <wchar.h>
# include <locale.h>
# include <limits.h>

int **n;

typedef struct			s_arg
{
	int					nb_arg;
	int					nb_prct;
	int					nb_bn;
	int					count_bn;
	int					ret;
	char				*type;
	size_t				*size;
	char				**strp;
	int					*length;
	long long			*i;
	unsigned long long	*ull;
	long double 		*d;
	int					**s;
	char				*str;
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

typedef struct			s_g
{
	char				c;
	char				*sign_nb;
	long long			i;
	long long			exp;
	int					num;
}						t_g;

int						ft_printf(const char *format, ...);
int						print_arg(t_arg *arg, t_flags *flags, int num);
int						printing(char *str, t_arg *arg, t_flags *flags, int num);
void					verif_next_arg(t_arg *arg, t_flags *flags, int next);
int 					interrupt(t_arg *arg, t_flags *flags);

int						*int_tab_malloc(int len);
long long				*ll_tab_malloc(int len);
unsigned long long		*ull_tab_malloc(int len);
char					*char_tab_malloc(int len);
size_t					*size_t_tab_malloc(int len);
char					**str_tab_malloc(int len);
int						**long_tab_malloc(int len);
long double				*dbl_tab_malloc(int len);

t_arg					*init_struct_arg(int len);
t_flags					*init_struct_flags(int len);
t_int					*init_struct_int(char *str, int num);
t_sign					*init_struct_sign(char a, t_arg *arg, int num);
t_g						*init_struct_g(t_arg *arg, t_flags *flags, int num, char c);

void					free_struct(t_arg *arg, t_flags *flags);
void					free_t_sign(t_sign *sign);
void					free_t_int(t_int *inc);
void					free_t_g(t_g *val);

void					init_flags(t_arg *arg, int i, t_flags *flags, int num);

int						print_char(t_arg *arg, t_flags *flags, int num);
char					*printable_w(long long w, t_arg *arg);
int						print_string(t_arg *arg, t_flags *flags, int num);
int						print_nb(t_arg *arg, t_flags *flags, int num);
int						print_base(int base, t_arg *arg, t_flags *flags, int num);
int						print_hex(char c, t_arg *arg, t_flags *flags, int num);
int						print_f(t_arg *arg, t_flags *flags, int num);
int						print_e(char c, t_arg *arg, t_flags *flags, int num);
int						print_g(char c, t_arg *arg, t_flags *flags, int num);
int						print_a(char a, t_arg *arg, t_flags *flags, int num);
int						print_la(char a, t_arg *arg, t_flags *flags, int num);
int						print_p(t_arg *arg, t_flags *flags, int num);

char					*process_flags(char *str, t_arg *arg, t_flags *flags, int num);
char					*htag_process(char *str, t_arg *arg, t_flags *flags, int num);
int						ft_color(const char *format, int i);

void					num_arg(const char *format, t_arg *arg, t_flags *flags);
int						nb_prct(const char *format);
int						len_and_type(const char *s, t_arg *arg, int num,
						t_flags *flags);
int						extract_value(char *s, t_arg *arg, t_flags *flags, int num);
void					width(t_arg *arg, t_flags *flags, int num);
void					process_strp(t_arg *arg, int num, t_flags *flags);
char					*char_tab_malloc(int len);
char					*pute(char *nb, char e, int exp, int nbb);
char					*round_g(char *nb);
char					*round_e(long long i, char *nb);
char					*round_f(char *nb);
void					ft_round_hex(double d, t_sign *sign, char *str);
char					*if_nbneg(char *str, int exp, char *signe, t_sign *sign);
char					*dtoa_base(long double d, t_sign *sign, int exp,
						long long precision);
char					*if_maj(char *str, char a);
int						ft_nblen(int nb);
long double				ft_power(long double e, long long *i, long long *exp);
char					*nb_g(double g, long long *exp, int precision, long long i);
char					*suppr_zero(char *nb);
void					stock_arg(va_list ap, t_arg *arg, t_flags *flags);
char					*itob(long long nb);
char					*add_plus_or_space(char *str, t_arg *arg, t_flags *flags,
						int num);
char					*ft_pr(long double g, t_flags *flags, t_g *val, char *nb);
long long				pr_zero(long double g);
double					ft_power_g(double e, long long *i, long long *exp);
char					*process_nb(double g, int i, int precision);
char					*putg(char *nb, long long nblen);

#endif
