#include "ft_printf.h"
#include <stdio.h>

char **perc_num(char **format, t_plchdr *res, va_list ap)
{
	res->p = 1;
	res->k = ' ';
	(*format)++;
	if (*(*format) == '*')
	{
		(*format)++;
		width_mod(format, ap, res);
	}
	if (NUM_MOD)
		get_width_len(format, res);
	return (format);
}

void put_perc(char *str, t_plchdr *res)
{
	intmax_t i;

	i = 0;
//	printf("%s\n", s);
	while (i < res->width && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
