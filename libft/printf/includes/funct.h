#ifndef FUNCT_H
# define FUNCT_H

# include "printf.h"

t_tf  tabf[] =
{
    {"cC\0", 0, &print_char},
    {"dDi\0", 0, &print_nb},
    {"sS\0", 0, &print_string},
    {"fF\0", 0, &print_f},
    {"aA\0", 0, &if_length},
    {"p\0", 0, &print_p},
    {"xX\0", 1, &print_hex},
    {"eE\0", 1, &print_e},
    {"gG\0", 1, &print_g},
    {NULL, NULL, NULL}
};

#endif