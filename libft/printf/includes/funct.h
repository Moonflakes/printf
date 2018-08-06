#ifndef FUNCT_H
# define FUNCT_H

# include "printf.h"

t_tf  tabf[] =
{
    {"cC\0", 0, &print_char, NULL},
    {"dDi\0", 0, &print_nb, NULL},
    {"sS\0", 0, &print_string, NULL},
    {"fF\0", 0, &print_f, NULL},
    {"aA\0", 0, &if_length, NULL},
    {"p\0", 0, &print_p, NULL},
    {"xX\0", 1, NULL, &print_hex},
    {"eE\0", 1, NULL, &print_e},
    {"gG\0", 1, NULL, &print_g},
    {"uUoOb\0", 2, NULL, &print_base},
    {NULL, 0, NULL, NULL}
};

#endif