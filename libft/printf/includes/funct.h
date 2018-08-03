#ifndef FUNCT_H
# define FUNCT_H

# include "printf.h"

t_tf  tabf[] =
{
    {"xX\0", "xXeEgG\0", &print_hex},
    {"cC\0", "xXeEgG\0", &print_char},
    {"dDi\0", "xXeEgG\0", &print_nb},
    {"sS\0", "xXeEgG\0", &print_string},
    {"fF\0", "xXeEgG\0", &print_f},
    {"aA\0", "xXeEgG\0", &if_length},
    {"p\0", "xXeEgG\0", &print_p},
  //  {"eE\0", "xXeEgG\0", &print_e},
    //{"gG\0", "xXeEgG\0", &print_g},
    {NULL, NULL, NULL}
};

#endif