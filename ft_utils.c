#include "header/ft_printf.h"
#include "header/libft.h"

int ft_convert_decimel_to_hexa(unsigned long number) {
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
    ft_putchar_fd('\n', 1);
    return i;
}

// int main()
// {
//     int     n = 32515;
//     ft_convert_decimel_to_hexa(n);
//     printf("\n%x", n);
//     return 0;
// }