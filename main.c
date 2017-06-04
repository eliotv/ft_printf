#include "src/libftprintf.h"
#include <stdio.h>
#include <limits.h>
//#include <locale.h>
int main(void)
{
	printf("\t%d\n", ft_printf("%s\n", NULL));
	printf("\t%d\n", printf("%s\n", NULL));
}
