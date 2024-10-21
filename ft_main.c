#include "header/ft_printf.h"
#include "header/libft.h"

int ft_printf(char *fmt, ...)
{
    int i = 0;
    va_list args;
    va_start(args, fmt);
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
                printf("This is a pointer\n");
                unsigned long ptr_add = va_arg(args, unsigned long);
                printf("Converting the pointer to hexadecimel\n");
                ft_putchar_fd('0', 1);
                ft_putchar_fd('x', 1);
                ft_convert_decimel_to_hexa(ptr_add);
                printf("Conversion ended\n");
                //printf("ptr_add %ld\n", ptr_add);
            }
            
        }
        else
        {
            ft_putchar_fd(fmt[i], 1);
        }
        i++;
    }
    return (1);
}