#include "ft_printf.h"

void function_hndlr(char c, va_list ap, t_plchdr res)
{
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

}
