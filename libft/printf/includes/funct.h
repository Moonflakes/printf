#ifndef FUNCT_H
# define FUNCT_H

# include "printf.h"

t_tf  tabf[] =
{
    {"cC\0" , &print_char},
    {"dDi\0" , &print_nb},
    {"sS\0" , &print_string},
    {"fF\0" , &print_f},
    {"aA\0" , &if_length},
    {"p\0" , &print_p},
    {NULL, NULL}
};

#endif