#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
int main(void)
{
	setlocale(LC_ALL, "");
//	ft_printf("ft_printf = %S\n", NULL);
//	printf("printf = %s\n", NULL);
	//ft_putstr("\n\n");
	ft_printf("ft_printf =%#+11x\n", -555);
//	ft_putchar('\n');
	printf("   printf =%#+11x\n", -555);

}
