#include "libft.h"

char	*ft_itoa_base(intmax_t value, int base)
{
	intmax_t n;
	int len;
	char *str;

	len = ft_count_int_len(value, base);
	n = value;
	if (n == 0)
		return (ft_strdup("0"));
	str = (char*)malloc(len + 1);
	if (!str)
		return (0);
	len--;
	str[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
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
