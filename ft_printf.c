#include "ft_printf.h"
#include <stdio.h>
void		search_format(char **str, char **format, va_list ap, t_plchdr res)
{
	char	f_i;

	while (**format)
	{
		if (*(*format) == '%')
		{
			(*format)++;
			while (!F_SPEC)
			{
				length_mod_ck(format, &res);
			//	(*format)++;
			}
//			res.s_str = ft_memalloc(res.len);
//			ft_strncpy(res.s_str, (*format) - res.len, res.len);
			if (F_SPEC)
			{
				f_i = (**format);
				function_hndlr(f_i, ap, res);
				(*format)++;
			}
		}
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
	va_end(ap);
	return (ft_strlen(format));
}
