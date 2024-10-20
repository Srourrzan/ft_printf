#include "header/ft_printf.h"
#include "header/libft.h"

int ft_convert_decimel_to_hexa(int number) {
    char hex[9];
    int i = 0;

    if (number == 0) {
        write(1, "0", 1);
        return 1;
    }

    while (number > 0) {
        int remainder = number % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'a'; 
        }
        number /= 16;
        i++;
    }

    while (i > 0) {
        write(1, &hex[--i], 1);
    }

    return i;
}

int main()
{
    int     n = 32515;
    ft_convert_decimel_to_hexa(n);
    printf("\n%x", n);
    return 0;
}