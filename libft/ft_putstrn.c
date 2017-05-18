#include "libft.h"

void ft_putstrn(char *str, intmax_t len)
{
	intmax_t i;

	i = 0;
	if (!str)
		return ;
	while (str[i] <= len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

