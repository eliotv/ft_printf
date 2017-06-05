#include "src/libftprintf.h"
#include <stdio.h>
#include <limits.h>
//#include <locale.h>
int main(void)
{
	printf("\t%d\n", ft_printf("@moulitest: %s", NULL));
	printf("\t%d\n", printf("@moulitest: %s", NULL));	
}
