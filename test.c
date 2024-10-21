#include "header/ft_printf.h"
#include "header/libft.h"

int main(void)
{
    //char    *str = "Razan Srour";
    int hex_num = 11252351;
    printf("O: hi there lower: %x, upper: %X \n", hex_num, hex_num);
    ft_printf("C: hi there lower: %x, upper: %X \n", hex_num, hex_num );

    return 0;
}