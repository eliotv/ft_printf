#ifndef FT_PRINTF_H
# define GET_NEXT_LINE_
# define F_SPEC (**format == 'c' || **format == 'd' || **format == 's' || **format == 'u' || **format == 'p' || **format == 'i' || **format == 'o' || **format == 'x' || **format == 'O' || **format == 'U' || **format == 'X' || **format == 'C' || **format == 'S' || **format == 'D')
# define L_MOD (**format == 'h' || **format == 'l' || **format == 'z' || **format == 'j' || **format == 't')
# define L_MOD1 (*(*format + 1) == 'h' || *(*format + 1) == 'l')
# define NUM_MOD (**format >= '0' && **format <= '9')
# define FLG_MOD (**format == '-' || **format == '0' || **format == ' ' || **format == '#' || **format == '+') 
#include "../libft/libft.h"
#include <stdarg.h>
#include <limits.h>
typedef struct		s_plchdr
{
	char *s_str;
	char *sign;
	intmax_t width;
	intmax_t len;
	intmax_t size;
	intmax_t p_n;
}					t_plchdr;
// build.c
t_plchdr			*init_res(intmax_t size);
// ft_printf.c
int					ft_printf(char const *format, ...);
void				search_format(char **str, char **format, va_list ap, t_plchdr *res);
// conversion.c functions
void				char_conv(t_plchdr res, va_list ap);
void				str_conv(t_plchdr res, va_list ap);
void				dec_conv(t_plchdr res, va_list ap);
void				uint_conv(t_plchdr res, va_list ap);
void				uint_oct_conv(t_plchdr res, va_list ap);
void				uint_hex_conv(t_plchdr res, va_list ap, char c);
void				pointer_adress(t_plchdr res, va_list ap);
// functionfinder.c
char				**function_hndlr(char **format, va_list ap, t_plchdr res);
//lenghmod.c
char				length_mod_ck(char **format, t_plchdr *res);
// widthmod.c
void				width_mod(char **format, va_list ap, t_plchdr *res);
void				put_width_spc(char *s, t_plchdr *res);
char				**get_width_len(char **format, t_plchdr *res);
// flagmod.c
void				flag_finder(char **format, t_plchdr *res);
#endif
