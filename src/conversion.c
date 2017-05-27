/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:18 by evanheum          #+#    #+#             */
/*   Updated: 2017/05/27 10:33:50 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void uint_conv(char  **format, t_plchdr *res, va_list ap)
{
	char *s;

	res->base = 10;
	if (**format == 'U')
		res->len = 3;
	s = base_conv(res, ap);
	if (res->width <= 1)
		res->size += ft_strlen(s);
	put_width_spc(format, s, res);
}

void uint_oct_conv(char **format, t_plchdr *res, va_list ap)
{
	char *s;

	res->base = 8;
	s = base_conv(res, ap);
	if (res->width <= 1)
		res->size += ft_strlen(s);
	put_width_spc(format, s, res);
}

void uint_hex_conv(char **format, t_plchdr *res, va_list ap, char c)
{
	char *s;
	int i;

	res->base = 16;
	s = base_conv(res, ap);
	if ( c == 'X')
	{
		i = -1;
		while (s[++i])
			s[i] = ft_toupper(s[i]);
	}
	if (res->width <= 1)
		res->size += ft_strlen(s);
	if (res->width < (intmax_t)ft_strlen(s) && res->size < (intmax_t)ft_strlen(s))
		res->size = ft_strlen(s);
	put_width_spc(format, s, res);
}

void pointer_adress(char **format, t_plchdr *res, va_list ap)
{
	char *s;
	char *hex;
	char *tmp;

	hex = "0x\0";
	s = ft_itoa_base(va_arg(ap, long long), 16);
	tmp = ft_strjoin(hex, s);
	if (res->width <= 1)
		res->size += ft_strlen(s);
	put_width_spc(format, tmp, res);
}

/*
void wchar_conv(t_plchdr res, va_list ap)
{
	char *s;

	s = (va_arg(ap, wchar_t*));
	put_width_spc(s, &res);
}*/
