#include "libftprintf.h"

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
		perc_width(format, res);
	return (format);
}

void put_perc(char **format, char *str, t_plchdr *res)
{
	intmax_t i;
	intmax_t n;

	i = 0;
	n = ft_strlen(str);
	if (**format != 's')
	{
		if (i < res->p_width && str[i])
			write(1, &str[i], n);
	}
	else
		while(i < res->p_width && str[i])
			write(1, &str[i++], 1);
}
/*
void perc_mod_width(t_plchdr *res)
{
	if (res->p_width > res->width)
	{
		res->size -= res->width;
		res->width = res->p_width;
		res->size += res->width;
	}
}*/