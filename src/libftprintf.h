/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:29 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/07 16:29:03 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#	define F_T (**format)
# define F_SPEC (F_T == 'c' || F_T == 'd' || F_T == 's' || F_T == 'u' || F_T == 'p' || F_T == 'i' || F_T == 'o' || F_T == 'x' || F_T == 'O' || F_T == 'U' || F_T == 'X' || F_T == 'C' ||F_T == 'S' || F_T == 'D' || F_T == '%')

# define L_MOD (F_T == 'h' || F_T == 'l' || F_T == 'z' || F_T == 'j')

# define L_MOD1 ((F_T + 1) == 'h' || (F_T + 1) == 'l')

# define NUM_MOD (F_T >= '0' && F_T <= '9')

# define FLG_MOD (F_T == '-' || F_T == '0' || F_T == ' ' || F_T == '#' || F_T == '+')

# define DIG_MOD (F_T == 'i' || F_T == 'D' || F_T == 'd' || F_T == 'x' || F_T == 'X' || F_T == 'o' || F_T == 'O' || F_T =='u' || F_T == 'U')

# define ALL_MOD (F_T == 'h' || F_T == 'l' || F_T == 'z' || F_T == 'j' || F_T == '-' || F_T == '0' || F_T == ' ' || F_T == '#' || F_T == '+' || F_T == '.' || F_T == '*' || (F_T >= '0' && F_T <= 9))

#include "../libft/libft.h"
#include <stdarg.h>
#include <limits.h>
typedef struct		s_plchdr
{
	char k;// storing ' ' or '0' for printing
	intmax_t sf;//space flag
	intmax_t width;//width mod
	intmax_t len;//len mod
	intmax_t size;//return size
	intmax_t plus;// if '+' set value 1
	intmax_t minus;// if '-' set value 1
	intmax_t p;//percision on/off
	intmax_t p_width;// width of percision
	intmax_t hash;// if '#' set value 1
	intmax_t neg;// negative numbers
	intmax_t base;// value you set for itoa and atoi conversions
	intmax_t null;//null passed
}					t_plchdr;
/*
**   --------------------  build.c  --------------------
*/
t_plchdr			*init_res(t_plchdr *res);
/*
**   -------------------  ft_printf.c  -----------------
*/
int					ft_printf(char const *format, ...);
int				search_format(char **format, va_list ap);
void  			search_flg_mod(char **format, va_list ap, t_plchdr *res);
void			print_format(char **format, t_plchdr *res);
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
void				uint_hex_conv(char **format, t_plchdr *res, va_list ap,
									char c);
void				pointer_adress(char **format, t_plchdr *res, va_list ap);
/*
**   -----------------  functionfinder.c  -------------
*/
void				function_hndlr(char **format, va_list ap, t_plchdr *res);
void				flag_finder(char **format, t_plchdr *res);
/*
**   -------------------  lengthmod.c  -----------------
*/
char				length_mod_ck(char **format, t_plchdr *res);
void				h_mod(char **format, t_plchdr *res);
void				ll_mod(char **format, t_plchdr *res);
void				z_mod(char **format, t_plchdr *res);
void				j_mod(char **format, t_plchdr *res);
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
int					percision_mod(char **format, t_plchdr *res, char *s, int n);
void				perc_p_mod(t_plchdr *res, char *s, char **format);
char				*perc_p_join(char *s, t_plchdr *res);
/*
**	--------------------	printf.c	----------------
*/
void				neg_flg_width(char **format, t_plchdr *res, char *s, int n);
void				pos_flg_width(char **format, t_plchdr *res, char *s, int n);
void				print_edge(char **format, t_plchdr *res, char *s, int n);
char				*edge_num_mod(t_plchdr *res, char **s, int n);
void				edge_p_width(char **format, char *s, t_plchdr *res);
/*
**	--------------------	printf2.c	----------------
*/
void				width_flg(char **format, t_plchdr *res, char *s, int n);
void				width_flg_2(char **format, t_plchdr *res, char *s, int n);
char				*width_num(char **format, t_plchdr *res, char **s, int n);

#endif
