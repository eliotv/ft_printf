#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define F_SPEC (**format == 'c' || **format == 'd' || **format == 's' || **format == 'u' || **format == 'p' || **format == 'i' || **format == 'o' || **format == 'x' || **format == 'O' || **format == 'U' || **format == 'X' || **format == 'C' || **format == 'S' || **format == 'D')
# define L_MOD (**format == 'h' || **format == 'l' || **format == 'z' || **format == 'j' || **format == 't')
# define L_MOD1 ((**format + 1) == 'h' || (**format + 1) == 'l')
# define NUM_MOD (**format >= '0' && **format <= '9')
# define FLG_MOD (**format == '-' || **format == '0' || **format == ' ' || **format == '#' || **format == '+') 
#include "../libft/libft.h"
#include <stdarg.h>
#include <limits.h>
typedef struct		s_plchdr
{
	char k;
	char *s_str;
	char *sign;
	intmax_t width;//width mod
	intmax_t len;//len mod
	intmax_t size;
	intmax_t plus;// if '+' set value 1
	intmax_t minus;// if '-' set value 1
	intmax_t p;
	intmax_t p_width;
	intmax_t hash;// if '#' set value 1
	intmax_t neg;
}					t_plchdr;
// build.c
t_plchdr			*init_res(intmax_t size);
// ft_printf.c
int					ft_printf(char const *format, ...);
void				search_format(char **format, va_list ap, t_plchdr *res);
// conversion.c functions
void				char_conv(char **format, t_plchdr *res, va_list ap);
void				str_conv(char **format, t_plchdr *res, va_list ap);
void				dec_conv(char **format, t_plchdr *res, va_list ap);
void				uint_conv(char **format, t_plchdr *res, va_list ap);
void				uint_oct_conv(char **format, t_plchdr *res, va_list ap);
void				uint_hex_conv(char **format, t_plchdr *res, va_list ap, char c);
void				pointer_adress(char **format, t_plchdr *res, va_list ap);
intmax_t			get_int(t_plchdr *res, va_list ap);
//void				wchar_conv(t_plchdr res, va_list ap);
// functionfinder.c
char				**function_hndlr(char **format, va_list ap, t_plchdr res);
//lenghmod.c
char				length_mod_ck(char **format, t_plchdr *res);
// widthmod.c
void				width_mod(char **format, va_list ap, t_plchdr *res);
void				put_width_spc(char **format, char *s, t_plchdr *res);
char				**get_width_len(char **format, t_plchdr *res);
char				**perc_width(char **format, t_plchdr *res);
// flagmod.c
void				flag_finder(char **format, t_plchdr *res);
void				hash_handler(char **format, t_plchdr *res);
// percisionmod.c
char				**perc_num(char **format, t_plchdr *res, va_list ap);
void				put_perc(char *str, t_plchdr *res);
#endif
