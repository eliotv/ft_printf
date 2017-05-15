#include "ft_printf.h"

char  **function_hndlr(char **format, va_list ap, t_plchdr res)
{
	char c;

	c = (**format);
	(*format)++;
	if (c == 'c' || c == 'C')
		char_conv(res, ap);
	if (c == 's')
		str_conv(res, ap);
	if (c == 'd' || c == 'D' || c == 'i')
		dec_conv(res, ap);
	if (c == 'u' || c == 'U')
		uint_conv(res, ap);
	if (c == 'o' || c == 'O')
		uint_oct_conv(res, ap);
	if (c == 'x' || c == 'X')
		uint_hex_conv(res, ap, c);
	if (c == 'p')
		pointer_adress(res, ap);
	return (format);
}
