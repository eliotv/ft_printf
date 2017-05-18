#include "libftprintf.h"

char  **function_hndlr(char **format, va_list ap, t_plchdr res)
{
	char c;

	c = (**format);
	if (c == 'c' || c == 'C')
		char_conv(format, &res, ap);
	if (c == 's')
		str_conv(format, &res, ap);
	if (c == 'd' || c == 'D' || c == 'i')
		dec_conv(format, &res, ap);
	if (c == 'u' || c == 'U')
		uint_conv(format, &res, ap);
	if (c == 'o' || c == 'O')
		uint_oct_conv(format, &res, ap);
	if (c == 'x' || c == 'X')
		uint_hex_conv(format, &res, ap, c);
	if (c == 'p')
		pointer_adress(format, &res, ap);
//	if (c == 'S')
//		wchar_conv(res, ap);

	(*format)++;
	return (format);
}
