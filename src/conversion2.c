#include "libftprintf.h"

void char_conv(char **format, t_plchdr *res, va_list ap)
{
	char c[2];

	if (**format == '%')
	{
		c[0] = '%';
		c[1] = '\0';
	}
	else
	{
		c[0] = va_arg(ap, int);
		c[1] = '\0';
	}
	if (res->width == 0)
		res->size = ft_strlen(c);
	put_width_spc(format, c, res);
}

void str_conv(char **format, t_plchdr *res, va_list ap)
{
	char *s;

	s = va_arg(ap, char*);
	if (res->width == 0)
		res->size = ft_strlen(s);
	put_width_spc(format, s, res);
}

intmax_t get_int(t_plchdr *res, va_list ap)
{

	if (res->len == 1)
		return((char)va_arg(ap, int));
	else if (res->len == 2)
		return((short)va_arg(ap, int));
	else if (res->len == 3)
		return((long)va_arg(ap, int));
	else if (res->len == 4)
		return((long long)va_arg(ap, int));
	else if (res->len == 5)
		return((size_t)va_arg(ap, int));
	else if (res->len == 6)
		return((intmax_t)va_arg(ap, int));
	else
		return(va_arg(ap, int));
}


void dec_conv(char **format, t_plchdr *res, va_list ap)
{
	intmax_t	nbr;
	char 		*s;

	nbr = get_int(res, ap);
	res->neg = (nbr < 0) ? -1 : 1;
	s = ft_itoa(nbr);
	if (res->width == 0)
		res->size = ft_strlen(s);
	put_width_spc(format, s, res);
}

char *base_conv(t_plchdr *res, va_list ap)
{
	if (res->len == 1)
		return (ft_itoa_base((char)va_arg(ap, unsigned int), res->base));
	else if (res->len == 2)
		return (ft_itoa_base((short)va_arg(ap, unsigned int), res->base));
	else if (res->len == 3)
		return (ft_itoa_base((long)va_arg(ap, unsigned int), res->base));
	else if (res->len == 4)
		return (ft_itoa_base((long long)va_arg(ap, unsigned int), res->base));
	else if (res->len == 5)
		return (ft_itoa_base((size_t)va_arg(ap, unsigned int), res->base));
	else if (res->len == 6)
		return (ft_itoa_base((intmax_t)va_arg(ap, unsigned int), res->base));
	else
		return (ft_itoa_base(va_arg(ap, unsigned int), res->base));
}
