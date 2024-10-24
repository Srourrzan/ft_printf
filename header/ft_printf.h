#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

int ft_printf(char *fmt, ...);
int ft_convert_decimel_to_hexa_p(unsigned long number);
int ft_convert_decimel_to_hexa_x(unsigned int number, char type);
int ft_convert_signed_to_unsigned(unsigned int number);

#endif
