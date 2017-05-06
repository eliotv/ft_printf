#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("ft_printf = u\n", 123123);
	printf("printf = %u\n", 123123);
	ft_putstr("\n\n");
	ft_printf("ft_printf = u\n", -123123);
	printf("printf = \n");
}
