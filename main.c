#include "src/libftprintf.h"
#include <stdio.h>
#include <limits.h>
//#include <locale.h>
int main(void)
{
	printf("\t%d", ft_printf("@moulitest: %s", NULL));
	ft_putchar('\n');
	printf("\t%d", printf("@moulitest: %s", NULL));
}
