#include "libft.h"

size_t	ft_count_unint_len(uintmax_t n, int base)
{
	size_t	i;

	i = 2;
	if (n == 0)
	{
		n = 0;
		return (i);
	}
	while (n /= base)
		i++;
	return (i);
}
