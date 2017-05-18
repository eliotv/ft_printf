#include "src/libftprintf.h"
#include <stdio.h>
#include <locale.h>
int main(void)
{
	int	x = -55;

	setlocale(LC_ALL, "");
//	ft_printf("ft_printf = %S\n", NULL);
//	printf("printf = %s\n", NULL);
	//ft_putstr("\n\n");
	ft_printf("ft_printf = {%#11d}\n", x);
//	ft_putchar('\n');
//	printf("   printf = {%#11d}\n", x);

}
