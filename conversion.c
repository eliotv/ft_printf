#include "ft_printf.h"

void char_conv(t_plchdr res, va_list ap)
{
	char c[2];

	c[0] = va_arg(ap, int);
	c[1] = '\0';
	ft_putstr(c);
}

void str_conv(t_plchdr res, va_list ap)
{
	char *s;

	s = va_arg(ap, char*);
	ft_putstr(s);
}

void dec_conv(t_plchdr res, va_list ap)
{
	char *s;

	if (res.len == 1)
		s = ft_itoa((char)va_arg(ap, int));
	if (res.len == 2)
		s = ft_itoa((short)va_arg(ap, int));
	if (res.len == 3)
		s = ft_itoa((long)va_arg(ap, int));
	if (res.len == 4)
		s = ft_itoa((long long)va_arg(ap, int));
	if (res.len == 5)
		s = ft_itoa((size_t)va_arg(ap, int));
	if (res.len == 6)
		s = ft_itoa((intmax_t)va_arg(ap, int));
	else
		s = ft_itoa(va_arg(ap, int));

	ft_putstr(s);
}

void uint_conv(t_plchdr res, va_list ap)
{
	char *s;

	if (res.len == 1)
		s = ft_itoa((unsigned char)va_arg(ap,  unsigned int));
	else if (res.len == 2)
		s = ft_itoa((unsigned short)va_arg(ap,  unsigned int));
	else if (res.len == 3)
		s = ft_itoa((long )va_arg(ap,  unsigned int));
	else if (res.len == 4)
		s = ft_itoa((long long)va_arg(ap,  unsigned int));
	else if( res.len == 5)
		s = ft_itoa((size_t)va_arg(ap,  unsigned int));
	else if (res.len == 6)
		s = ft_itoa((intmax_t)va_arg(ap,  unsigned int));
	else
		s = ft_itoa(va_arg(ap,  unsigned int));
	ft_putstr(s);
}

void uint_oct_conv(t_plchdr res, va_list ap)
{
	char *s;

	if (res.len == 1)
		s = ft_itoa_base((char)va_arg(ap, unsigned int), 8);
	if (res.len == 2)
		s = ft_itoa_base((short)va_arg(ap, unsigned int), 8);
	if (res.len == 3)
		s = ft_itoa_base((long)va_arg(ap, unsigned int), 8);
	if (res.len == 4)
		s = ft_itoa_base((long long)va_arg(ap, unsigned int), 8);
	if (res.len == 5)
		s = ft_itoa_base((size_t)va_arg(ap, unsigned int), 8);
	if (res.len == 6)
		s = ft_itoa_base((intmax_t)va_arg(ap, unsigned int), 8);
	else
		s = ft_itoa_base(va_arg(ap, unsigned int), 8);
	ft_putstr(s);
}

void uint_hex_conv(t_plchdr res, va_list ap, char c)
{
	char *s;
	int i;

	s = ft_itoa_base(va_arg(ap, unsigned int), 16);
	if ( c == 'X')
	{
		i = 0;
		while (s[i++])
			s[i] = ft_toupper(s[i]);
	}
	ft_putstr(s);
}

void pointer_adress(t_plchdr res, va_list ap)
{
	char *s;
	char *hex;
	char *tmp;

	hex = "0x\0";
	s = ft_itoa_base(va_arg(ap, long long), 16);
	tmp = ft_strjoin(hex, s);
	ft_putstr(tmp);
}
