#include "ft_printf.h"
#include <stdio.h>
void		search_format(char **str, char **format, va_list ap, t_plchdr res)
{
	char	*tmp;
	char	f_i;

	tmp = NULL;
	while (**format)
	{
		if (**format == '%')
		{
//			ft_strcat(res.res, format - 1);
			f_i  = ++(**format);
//		format = ft_strdup(tmp + 1);
//		format = tmp;
//		printf("format = %s\n", format);
//		ft_strcat(res.res, format);
			if (f_i == 'c')
				char_conv(res, ap);
			if (f_i == 's')
				str_conv(res, ap);
			if (f_i == 'd')
				dec_conv(res, ap);	
//		if (f_i == 'p')
//		if (f_i == 'i')
//		if (f_i == 'o')
			if (f_i == 'u')
				uint_conv(res, ap);
//		if (f_i == 'x')
//		if (f_i == 'O')
//		if (f_i == 'U')
//		if (f_i == 'X')
//		if (f_i == 'C')
//		if (f_i == 'S')
//		if (f_i == 'D')
//			if (*++tmp == '\n')
//				append_str(res.s_str, '\n');
//		res.test = ft_strjoin(res.res, res.s_str);
		}
		else
			ft_putchar(**format);
		(*format)++;
	}
}



int ft_printf(const char *format, ...)
{
	va_list ap;
	t_plchdr res;
	char *str;
	
	res = init_res(25);
	va_start(ap, format);
	search_format(&str,(char**)&format, ap, res);
//	ft_putstr(res.res);
	ft_putstr(res.s_str);
	va_end(ap);
	return (ft_strlen(res.s_str));
}
