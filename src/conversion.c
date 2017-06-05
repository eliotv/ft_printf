/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:18 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/03 18:48:42 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			uint_conv(char  **format, t_plchdr *res, va_list ap)
{
	char		*s;

	res->base = 10;
	if (**format == 'U')
		res->len = 3;
	s = base_conv(res, ap);
	if (res->width <= 1)
		res->size += ft_strlen(s);
	if (res->size < (intmax_t)ft_strlen(s))
		res->size = ft_strlen(s);
	put_width_spc(format, s, res);
	ft_strdel(&s);
}

void			uint_oct_conv(char **format, t_plchdr *res, va_list ap)
{
	char		*s;

	res->base = 8;
	if (**format == 'O')
		res->len = 3;
	s = base_conv(res, ap);
	if (res->width <= 1)
		res->size += ft_strlen(s);
	put_width_spc(format, s, res);
	ft_strdel(&s);
}

void			uint_hex_conv(char **format, t_plchdr *res, va_list ap, char c)
{
	char		*s;
	int			i;

	res->base = 16;
	s = base_conv(res, ap);
	if (c == 'X')
	{
		i = -1;
		while (s[++i])
			s[i] = ft_toupper(s[i]);
	}
	(res->width <= 1) ? res->size += ft_strlen(s) : 0;
	(res->width < (intmax_t)ft_strlen(s) && res->size < (intmax_t)ft_strlen(s))
		? res->size = ft_strlen(s) : 0;
	put_width_spc(format, s, res);
	ft_strdel(&s);
}

void	pointer_adress(char **format, t_plchdr *res, va_list ap)
{
	char *s;
	char *hex;
	char *tmp;

	hex = "0x";
	res->size += 2;
	if (res->p == 1 && res->p_width == 0)
	{
		ft_putstr(hex);
		NULL;
	}
	s = ft_itoa_base(va_arg(ap, long long), 16);
	tmp = ft_strjoin(hex, s);
	free(s);
	(res->width <= 1) ? res->size += ft_strlen(tmp) : 0;
	put_width_spc(format, tmp, res);
	ft_strdel(&tmp);
}
