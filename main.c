#include "src/libftprintf.h"
#include <stdio.h>
//#include <locale.h>
int main(void)
{
//	setlocale(LC_ALL, "");
//	ft_printf("ft_printf = %S\n", NULL);
//	printf("printf = %s\n", NULL);
	//ft_putstr("\n\n");	
	ft_printf("%-.2s is a string", "this");
	ft_putchar('\n');
//	printf("%5.2s is a string", "");
//	printf("   printf = %d%s", 42, "255");
//	printf("   printf = %X", 42);
}
