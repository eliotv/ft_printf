/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:29 by evanheum          #+#    #+#             */
/*   Updated: 2017/05/27 10:33:43 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define F_SPEC (**format == 'c' || **format == 'd' || **format == 's' || **format == 'u' || **format == 'p' || **format == 'i' || **format == 'o' || **format == 'x' || **format == 'O' || **format == 'U' || **format == 'X' || **format == 'C' || **format == 'S' || **format == 'D' || **format == '%')
# define L_MOD (**format == 'h' || **format == 'l' || **format == 'z' || **format == 'j' || **format == 't')
# define L_MOD1 ((**format + 1) == 'h' || (**format + 1) == 'l')
# define NUM_MOD (**format >= '0' && **format <= '9')
# define FLG_MOD (**format == '-' || **format == '0' || **format == ' ' || **format == '#' || **format == '+')
# define DIG_MOD (**format == 'i' || **format == 'D' || **format == 'd' || **format == 'x' || **format == 'X' || **format == 'o' || **format == 'O' || **format =='u' || **format == 'U')
#include "../libft/libft.h"
#include <stdarg.h>
#include <limits.h>
typedef struct		s_plchdr
{
	char k;
	intmax_t sf;
	intmax_t width;//width mod
	intmax_t len;//len mod
	intmax_t size;
	intmax_t plus;// if '+' set value 1
	intmax_t minus;// if '-' set value 1
	intmax_t p;
	intmax_t p_width;
	intmax_t hash;// if '#' set value 1
	intmax_t neg;// negative numbers
	intmax_t base;// value you set for itoa and atoi conversions

}					t_plchdr;
/*
**   --------------------  build.c  --------------------
*/
t_plchdr			*init_res(t_plchdr *res);
/*
**   -------------------  ft_printf.c  -----------------
*/
int					ft_printf(char const *format, ...);
void				search_format(char **format, va_list ap, t_plchdr *res);
/*
**   ------------------  conversion2.c  ----------------
*/
void				char_conv(char **format, t_plchdr *res, va_list ap);
void				str_conv(char **format, t_plchdr *res, va_list ap);
void				dec_conv(char **format, t_plchdr *res, va_list ap);
intmax_t			get_int(t_plchdr *res, va_list ap);
char				*base_conv(t_plchdr *res, va_list ap);
/*
**   -------------------  conversion.c  ---------------
*/
void				uint_conv(char **format, t_plchdr *res, va_list ap);
void				uint_oct_conv(char **format, t_plchdr *res, va_list ap);
void				uint_hex_conv(char **format, t_plchdr *res, va_list ap, char c);
void				pointer_adress(char **format, t_plchdr *res, va_list ap);
//void				wchar_conv(t_plchdr res, va_list ap);
/*
**   -----------------  functionfinder.c  -------------
*/
void				function_hndlr(char **format, va_list ap, t_plchdr *res);
void				flag_finder(char **format, t_plchdr *res);
/*
**   -------------------  lengthmod.c  -----------------
*/
char				length_mod_ck(char **format, t_plchdr *res);
/*
**   -------------------  widthmod.c  ------------------
*/
void				width_mod(char **format, va_list ap, t_plchdr *res);
void				put_width_spc(char **format, char *s, t_plchdr *res);
char				**get_width_len(char **format, t_plchdr *res);
char				**perc_width(char **format, t_plchdr *res);
void				put_str(char *str, int len);
/*
**   -------------------  flagmod.c  -------------------
*/
void				hash_handler(char **format, t_plchdr *res);
char				**minus_flag(char **format, t_plchdr *res);
char				**plus_flag(char **format, t_plchdr *res);
char				**zero_flag(char **format, t_plchdr *res);
void				space_flag(char **format, char *s, t_plchdr *res);
/*
**   -------------------  percisionmod.c  --------------
*/
char				**perc_num(char **format, t_plchdr *res, va_list ap);
void				put_perc(char **format, char *str, t_plchdr *res);

#endif
