#include "src/libftprintf.h"
#include <stdio.h>
#include <limits.h>
//#include <locale.h>
int main(void)
{
//	printf("\t%d\n", ft_printf("%8.4o", 424242424));
//	printf("\t%d\n", printf("%8.4o", 424242424));
//	printf("\t%d\n", ft_printf("%4.15o", 42));
//	printf("\t%d\n", printf("%4.15o", 42));
	printf("\t%d\n", ft_printf("%4.15X", 42));
	printf("\t%d\n", printf("%4.15X", 42));
//	printf("\t%d\n", ft_printf("%4.8o", 424242424));
//	printf("\t%d\n", printf("%4.8o", 424242424));
}
