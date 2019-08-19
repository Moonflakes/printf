/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:06:09 by mthiery           #+#    #+#             */
/*   Updated: 2018/05/07 12:36:45 by mthiery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCT_H
# define FUNCT_H

# include "printf.h"

t_tf    tabf[]  =
{
    {"cC\0", 0, &print_char, NULL},
    {"dDi\0", 0, &print_nb, NULL},
    {"sS\0", 0, &print_string, NULL},
    {"fF\0", 0, &print_f, NULL},
    {"p\0", 0, &print_p, NULL},
    {"aA\0", 1, NULL, &print_a},
    {"xX\0", 1, NULL, &print_hex},
    {"eE\0", 1, NULL, &print_e},
    {"gG\0", 1, NULL, &print_g},
    {"uUoOb\0", 2, NULL, &print_base},
    {NULL, 0, NULL, NULL}
};

#endif
