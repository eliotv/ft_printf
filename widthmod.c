#include "ft_printf.h"
#include <stdio.h>

void	width_mod(char **format, va_list ap, t_plchdr *res)
{
	res->width = va_arg(ap, intmax_t);
	(*format)++;
}

void put_width_spc(char *s, t_plchdr *res)
{
	intmax_t n;

	n = ft_strlen(s);
	if (n < res->width && res->p_n == -1 && n >= 0)
	{
		ft_putstr(s);
		while(n < res->width--)
			ft_putchar(' ');
	}
	else if (n < res->width && res->p_n == 1)
	{
		while (n < res->width--)
			ft_putchar(' ');
		ft_putstr(s);
	}
	else if (n < res->width && res->p_n == 2)
	{
		while (n < --res->width)
			ft_putchar(' ');
		ft_putchar('+');
		ft_putstr(s);
	}
	else
		ft_putstr(s);
}

char **get_width_len(char **format, t_plchdr *res)
{
	res->width = ft_atoi(*format);
	while (!F_SPEC)
		(*format)++;
	return (format);
}