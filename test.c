#include "header/ft_printf.h"
#include "header/libft.h"

int	main(void)
{
	int number = 1996;
	int x = 0;
	int y = 0;
	x += ft_printf(" %x ", number);
	// x += ft_printf(" %d ", 1);
	// x += ft_printf(" %d ", 15);
	printf("Length of char printed using ft_printf = %d\n", x);
	printf("\n------------------------------\n");
	y += printf(" %x ", number);
	// y += printf(" %d ", 1);
	// y += printf(" %d ", 15);
	printf("Length of char printed using printf = %d\n", y);
	printf("\n------------------------------\n");

	return (0);
}