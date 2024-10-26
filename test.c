#include "header/ft_printf.h"
#include "header/libft.h"

int	main(void)
{
	int number = -958302;
	int x = 0;
	int y = 0;
	x += ft_printf(" %p ", -1);
	x += ft_printf(" %p ", 1);
	x += ft_printf(" %p ", 15);
	printf("\n------------------------------\n");
	y += printf(" %p ", -1);
	y += printf(" %p ", 1);
	y += printf(" %p ", 15);
	printf("\n------------------------------\n");

	return (0);
}