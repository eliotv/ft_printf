#include "ft_printf.h"

void char_conv(char **format, t_plchdr *res, va_list ap)
{
	char c[2];

	c[0] = va_arg(ap, int);
	c[1] = '\0';
//	if (res->p == 1)
//		put_perc(c, res);
	put_width_spc(format, c, res);	
}

void str_conv(char **format, t_plchdr *res, va_list ap)
{
	char *s;

	s = va_arg(ap, char*);
//	if (res->p == 1)
//		put_perc(s, res);
	put_width_spc(format, s, res);	
}

intmax_t get_int(char **format, t_plchdr *res, va_list ap)
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

	nbr = get_int(format, res, ap);
	res->neg = (nbr < 0) ? -1 : 1;
	s = ft_itoa(nbr);
	put_width_spc(format, s, res);
}
/*
void dec_conv(char **format, t_plchdr *res, va_list ap)
{
	char *s;

	if (res->len == 1)
		s = ft_itoa((char)va_arg(ap, int));
	else if (res->len == 2)
		s = ft_itoa((short)va_arg(ap, int));
	else if (res->len == 3)
		s = ft_itoa((long)va_arg(ap, int));
	else if (res->len == 4)
		s = ft_itoa((long long)va_arg(ap, int));
	else if (res->len == 5)
		s = ft_itoa((size_t)va_arg(ap, int));
	else if (res->len == 6)
		s = ft_itoa((intmax_t)va_arg(ap, int));
	else
		s = ft_itoa(va_arg(ap, int));
//	if (res->p == 1)
//		put_perc(s, res);
//
	put_width_spc(format, s, res);
}*/

void uint_conv(char  **format, t_plchdr *res, va_list ap)
{
	char *s;

	if (res->len == 1)
		s = ft_itoa((unsigned char)va_arg(ap,  unsigned int));
	else if (res->len == 2)
		s = ft_itoa((unsigned short)va_arg(ap,  unsigned int));
	else if (res->len == 3)
		s = ft_itoa((long )va_arg(ap,  unsigned int));
	else if (res->len == 4)
		s = ft_itoa((long long)va_arg(ap,  unsigned int));
	else if( res->len == 5)
		s = ft_itoa((size_t)va_arg(ap,  unsigned int));
	else if (res->len == 6)
		s = ft_itoa((intmax_t)va_arg(ap,  unsigned int));
	else
		s = ft_itoa(va_arg(ap,  unsigned int));
//	if (res->p == 1)
//		put_perc(s, res);
	put_width_spc(format, s, res);
}

void uint_oct_conv(char **format, t_plchdr *res, va_list ap)
{
	char *s;

	if (res->len == 1)
		s = ft_itoa_base((char)va_arg(ap, unsigned int), 8);
	else if (res->len == 2)
		s = ft_itoa_base((short)va_arg(ap, unsigned int), 8);
	else if (res->len == 3)
		s = ft_itoa_base((long)va_arg(ap, unsigned int), 8);
	else if (res->len == 4)
		s = ft_itoa_base((long long)va_arg(ap, unsigned int), 8);
	else if (res->len == 5)
		s = ft_itoa_base((size_t)va_arg(ap, unsigned int), 8);
	else if (res->len == 6)
		s = ft_itoa_base((intmax_t)va_arg(ap, unsigned int), 8);
	else
		s = ft_itoa_base(va_arg(ap, unsigned int), 8);
//	if (res->p == 1)
//		put_perc(s, res);
	put_width_spc(format, s, res);
}

void uint_hex_conv(char **format, t_plchdr *res, va_list ap, char c)
{
	char *s;
	int i;

	s = ft_itoa_base(va_arg(ap, unsigned int), 16);
	if ( c == 'X')
	{
		i = -1;
		while (s[++i])
			s[i] = ft_toupper(s[i]);
	}
//	if (res->p == 1)
//		put_perc(s, res);
	put_width_spc(format, s, res);
}

void pointer_adress(char **format, t_plchdr *res, va_list ap)
{
	char *s;
	char *hex;
	char *tmp;

	hex = "0x\0";
	s = ft_itoa_base(va_arg(ap, long long), 16);
	tmp = ft_strjoin(hex, s);
//	if (res->p == 1)
//		put_perc(s, res);
	put_width_spc(format, tmp, res);
}
/*
void wchar_conv(t_plchdr res, va_list ap)
{
	char *s;

	s = (va_arg(ap, wchar_t*));
	put_width_spc(s, &res);
}*/
