#include "libft.h"

char	*ft_un_itoa_base(uintmax_t value, int base)
{
	uintmax_t n;
	int len;
	char *str;

	len = ft_count_unint_len(value, base);
	n = value;
	str = (char*)ft_memalloc(len + 1);
	if (!str)
		return (0);
	len--;
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		if (n % base <= 9)
			str[--len] = (n % base) + '0';
		else
			str[--len] = (n % base) + 87;
		n = n / base;
	}
	return (str);
}
