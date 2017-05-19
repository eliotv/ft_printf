#include "libftprintf.h"

void		search_format(char **format, va_list ap, t_plchdr *res)
{
	while (**format)
	{
		if (**format == '%')
		{
			res = init_res(res);
			(*format)++;
			if (FLG_MOD)
				flag_finder(format, res);
			if (NUM_MOD)
				get_width_len(format, res);
			if (*(*format) == '.')
				perc_num(format, res, ap);
			if (*(*format) == '*')
				width_mod(format ,ap, res);
			if (!F_SPEC)
				length_mod_ck(format, res);
			if (F_SPEC)
				function_hndlr(format, ap, *res);
		}
		res->size++;
		ft_putchar(**format);	
		(*format)++;
	}
}



int ft_printf(const char *format, ...)
{
	va_list ap;
	t_plchdr *res;

	res = NULL;
	res = init_res(res);
	va_start(ap, format);
	search_format((char**)&format, ap, res);
	va_end(ap);
	return (res->size);
}
