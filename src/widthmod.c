#include "ft_printf.h"

void	width_mod(char **format, va_list ap, t_plchdr *res)
{
	res->width = va_arg(ap, intmax_t);
	(*format)++;
}

void put_width_spc(char **format, char *s, t_plchdr *res)
{
	intmax_t n;

	n = ft_strlen(s);
	if (n < res->width && res->minus == 1 && n >= 0)
	{
		if (res->hash == 1)
		{
			hash_handler(format, res);
		}
		if (res->plus == 1)
		{
			ft_putchar('+');
			res->width--;
		}
		ft_putstr(s);
		while(n < res->width--)
			ft_putstr(&res->k);
	}
	else if (n < res->width && res->plus == 1)
	{
		if (res->k == '0')
			ft_putchar('+');
		if (res->hash == 1)
			res->width--;
		while(n < res->width--)
			ft_putstr(&res->k);
		if (res->hash == 1)
			hash_handler(format, res);
		if (res->k == ' ' && res->plus == 1 && **format == 'd')
			ft_putchar('+');
		ft_putstr(s);
	}
	else if (n < res->width)
	{
	
		if (res->hash == 1)
			res->width--;
		if (res->plus == 1)
			ft_putchar('+');
		while (n < res->width--)
			ft_putstr(&res->k);
		hash_handler(format, res);
		ft_putstr(s);
	}
	else
	{
		if(res->plus == 1)
			ft_putchar('+');
	}
		ft_putstr(s);
}

char **get_width_len(char **format, t_plchdr *res)
{
	res->width = ft_atoi(*format);
	while (!F_SPEC)
		(*format)++;
	return (format);
}
