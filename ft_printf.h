#ifndef FT_PRINTF_H
# define GET_NEXT_LINE_H

#include "../libft/libft.h"
#include <stdarg.h>

typedef struct		s_plchdr
{
	char *s_str;
	char *res;
	char *test;
	intmax_t len;
	intmax_t size;
}					t_plchdr;

t_plchdr			init_res(intmax_t size);
void				append_str(char *s, char c);

int					ft_printf(char const *format, ...);

void				search_format(char **str, char **format, va_list ap, t_plchdr res);

// conversion.c functions
void				char_conv(t_plchdr res, va_list ap);
void				str_conv(t_plchdr res, va_list ap);
void				dec_conv(t_plchdr res, va_list ap);
void				uint_conv(t_plchdr res, va_list ap);


#endif
