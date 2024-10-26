#include "header/ft_printf.h"
#include "header/libft.h"

int ft_convert_decimel_to_hexa_p(unsigned long number) {
    char hex[100];
    int i;
    int remainder;

    i = 0;
    if (number == 0) {
        printf("number os 0");
        ft_putchar_fd('0', 1);
        return 1;
    }
    while (number > 0) {
        remainder = number % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'a'; 
        }
        number /= 16;
        i++;
    }
    hex[i] = '\0';
    i--;
    while (i > 0) {
        ft_putchar_fd(hex[--i], 1);
    }
    //ft_putchar_fd('\n', 1);
    return i;
}

int ft_convert_decimel_to_hexa_x(unsigned int number, char type) {
    char hex[100];
    int i;
    int remainder;

    i = 0;
    if (number == 0) {
        ft_putchar_fd('0', 1);
        return 1;
    }
    while (number > 0) {
        remainder = number % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            if (type == 'x')
                hex[i] = remainder - 10 + 'a'; 
            else if (type == 'X')
                hex[i] = remainder - 10 + 'A';
        }
        number /= 16;
        i++;
    }
    hex[i] = '\0';   
    while (i > 0) {
        ft_putchar_fd(hex[--i], 1);
    }
    return i;
}

int ft_convert_signed_to_unsigned(unsigned int number)
{
    char    *n_base;
    int         len;
    size_t      aux;
    int         str_len;

    len = 0;
    aux = number;
    if (number == 0)
        len = 1;
    while (aux != 0)
    {
        aux /= 10;
        len++;
    }
    n_base = malloc(sizeof(char) * (len+1));
    if (!n_base)
        return (NULL);
    n_base[len] = '\0';
    while (len--)
    {
        n_base[len] = number % 10 + '0';
        number /= 10;
    }
    str_len = write(1, n_base, ft_strlen(n_base)*sizeof(char));
    free(n_base);
    return (str_len);
}

// int main()
// {
//     int     n = 32515;
//     ft_convert_decimel_to_hexa(n);
//     printf("\n%x", n);
//     return 0;
// }