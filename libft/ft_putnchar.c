#include "libft.h"

void ft_putnchar(char c, intmax_t i)
{
	while (i-- > 0)
		ft_putchar(c);
}
