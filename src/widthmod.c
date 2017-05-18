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
	if (res->p == 1)
	{
		if (res->plus == 1 && res->minus == 0)
		{
			n = res->p_width - 1;
			if(res->hash == 0)
				res->width--;
		}	
		else
			n = res->p_width;
	}
	if (n < res->width && res->minus == 1 && n >= 0)
	{
		if (res->hash == 1)
		{
			hash_handler(format, res);
		}
		if (res->plus == 1 && res->hash == 0 && res->p == 0)
		{
			ft_putchar('+');
			res->width--;
		}
		if (res->p == 1)
			put_perc(s, res);
		else
			ft_putstr(s);
		while(n < res->width--)
			ft_putstr(&res->k);
	}
	else if (n < res->width && res->plus == 1)
	{
		if (res->k == '0')
			ft_putchar('+');
		if (res->hash == 1 && res->p == 1)
			res->width--;
		if (res->hash == 1 &&((**format == 'o') || (**format == 'x') || (**format == 'X')))
			res->width--;
		while(n < res->width--)
			ft_putstr(&res->k);
		if (res->hash == 1)
			hash_handler(format, res);
		if (res->k == ' ' && res->plus == 1 && res->neg != -1 && **format == 'd')
			ft_putchar('+');
		if (res->p == 1)
			put_perc(s, res);
		else
			ft_putstr(s);
	}
	else if (n < res->width)
	{
	
		if (res->hash == 1 && res->p == 0 && **format != 's' && **format != 'd')
			res->width--;
		if (res->hash == 1 && ((**format == 'o') || (**format == 'x') || (**format == 'X')))
			res->width--;
		if (res->plus == 1 && res->hash == 0)
			ft_putchar('+');
		while (n < res->width--)
			ft_putstr(&res->k);
		hash_handler(format, res);
		if (res->p == 1)
			put_perc(s, res);
		else
			ft_putstr(s);
	}
	else
	{
		if(res->plus == 1)
			ft_putchar('+');
		ft_putstr(s);
	}
}

char **get_width_len(char **format, t_plchdr *res)
{
	res->width = ft_atoi(*format);
	while (!F_SPEC)
	{
		if (**format == '.')
		{
			res->p = 1;
			(*format)++;
			res->p_width = ft_atoi(*format);
		}
		(*format)++;
	}
	if (**format != 's')
		res->p = 0;
	return (format);
}

char **perc_width(char **format, t_plchdr *res)
{
	res->p_width = ft_atoi(*format);
	while (!F_SPEC)
		(*format)++;
	return (format);
}
