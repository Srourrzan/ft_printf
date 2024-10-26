#include "header/ft_printf.h"
#include "header/libft.h"

int ft_printf(char *fmt, ...)
{
    int i = 0;
    int num_char;
    va_list args;
    va_start(args, fmt);

    num_char = 0;
    while(fmt[i])
    {
        if(fmt[i] == '%')
        {
            i++;
            if(fmt[i] == 'i' || fmt[i] == 'd')
            {
                int x = va_arg(args, int);
                ft_putnbr_fd(x, 1);
            }
            else if(fmt[i] == '%')
            {
                ft_putchar_fd('%', 1);
            }
            else if(fmt[i] == 'c')
            {
                char x = va_arg(args, int);
                ft_putchar_fd(x, 1);
            }
            else if(fmt[i] == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    ft_putchar_fd(*str++, 1);
                }
            }
            else if (fmt[i] == 'p')
            {
                unsigned long ptr_add = va_arg(args, unsigned long);
                ft_putchar_fd('0', 1);
                ft_putchar_fd('x', 1);
                num_char += ft_convert_decimel_to_hexa_p(ptr_add);
                num_char += 2;
            }
            else if (fmt[i] == 'x' || fmt[i] == 'X')
            {
                unsigned int x_value = va_arg(args, unsigned int);
                num_char += ft_convert_decimel_to_hexa_x(x_value, fmt[i]);
            }
            else if (fmt[i] == 'u')
            {
                unsigned int u_value = va_arg(args, unsigned int);
                num_char += ft_convert_signed_to_unsigned(u_value);
            }
        }
        else
        {
            ft_putchar_fd(fmt[i], 1);
        }
        i++;
        va_end(args);
    }
    return (i + num_char);
}