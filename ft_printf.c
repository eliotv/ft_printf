#include "ft_printf.h"
#include <stdio.h>
void		search_format(char **str, char **format, va_list ap, t_plchdr *res)
{
	char	f_i;

	while (**format)
	{
		if (*(*format) == '%')
		{
			(*format)++;
			if (*(*format) == '-')
			{
				res->p_n = -1;
				(*format)++;
			}
			if (NUM_MOD)
				get_width_len(format, res);
			if (*(*format) == '*')
			{
				width_mod(format ,ap, res);
			}
			if (!F_SPEC)
			{
				length_mod_ck(format, res);
			}
			if (F_SPEC)
			{
				f_i = (**format);
				function_hndlr(f_i, ap, *res);
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
	t_plchdr *res;
	char *str;
	
	res = init_res(25);
	va_start(ap, format);
	search_format(&str,(char**)&format, ap, res);
	va_end(ap);
	return (ft_strlen(format));
}
