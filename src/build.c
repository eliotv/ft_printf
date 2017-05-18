#include "ft_printf.h"

t_plchdr *init_res(intmax_t size)
{
	t_plchdr	*res;

	res = (t_plchdr*)malloc(sizeof(t_plchdr));
	res->size = size;
	res->len = 0;
	res->width = 0;
	res->plus = 0;
	res->k = ' ';
	res->p = 0;
	res->p_width = 0;
	res->hash = 0;
	res->minus = 0;
	
	res->s_str = malloc(sizeof(25));
	return (res);
}

//void convert(char c, char **fmt, t_plchdr res, va_list ap)
//{
//	f_i = (**format);
//	function_hndlr(c, ap, res);

