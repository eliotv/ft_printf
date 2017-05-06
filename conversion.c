#include "ft_printf.h"

void char_conv(t_plchdr res, va_list ap)
{
	char c[2];
//	char *str;

//	str = ap; 
//	if (ft_strlen(ap) > 1)
//		return ;
	c[0] = va_arg(ap, int);
	c[1] = '\0';
	ft_strcat(res.s_str, c);
}

void str_conv(t_plchdr res, va_list ap)
{
	char *s;

	s = va_arg(ap, char*);
	ft_strcat(res.s_str, s);
}

void dec_conv(t_plchdr res, va_list ap)
{
	char *s;

	s = ft_itoa(va_arg(ap, int));
	ft_strcat(res.s_str, s);
}

void uint_conv(t_plchdr res, va_list ap)
{
	char *s;

	s = ft_itoa(va_arg(ap,  unsigned int));
	ft_strcat(res.s_str, s);
}
