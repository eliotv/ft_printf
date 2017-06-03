#include "src/libftprintf.h"
#include <stdio.h>
#include <limits.h>
//#include <locale.h>
int main(void)
{
	printf("\t%d\n", ft_printf("%4.15d", 42));
	printf("\t%d\n", printf("%4.15d", 42));
}
