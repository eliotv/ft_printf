/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:03 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/02 12:18:30 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void						char_conv(char **format, t_plchdr *res, va_list ap)
{
	char					c[2];

	if (**format == '%')
	{
		c[0] = '%';
		c[1] = '\0';
	}
	else
	{
		c[0] = va_arg(ap, int);
		c[1] = '\0';
		(c[0] == 0) ? res->null = 1 : 0;
	}
	if (res->width == 0)
	{
		if (*c == '\0')
			res->size++;
		res->size += ft_strlen(c);
	}
	put_width_spc(format, c, res);
}

void						str_conv(char **format, t_plchdr *res, va_list ap)
{
	char					*s;
	intmax_t			tmp;

	tmp = 0;
	s = va_arg(ap, char*);
	if (!s)
	{
		s = ft_strdup("(null)");
		res->size += 6;
	}
	else if (res->p == 1 && res->width == 0)
	{
		if (res->p_width > (intmax_t)ft_strlen(s))
			tmp = res->p_width - ft_strlen(s);
		else if ((intmax_t)ft_strlen(s) > res->p_width)
			tmp = (ft_strlen(s) - res->p_width);
		if (tmp > 0 && ft_strlen(s) > 0)
			res->size += tmp;
	}
	else if (res->width == 0 && res->minus == 0)
	{
		res->size += ft_strlen(s);
		(res->size > 0) ? res->size -= res->p_width : 0;
	}
	put_width_spc(format, s, res);
}

intmax_t			get_int(t_plchdr *res, va_list ap)
{
	if (res->len == 1)
		return ((char)va_arg(ap, int));
	else if (res->len == 2)
		return ((short)va_arg(ap, int));
	else if (res->len == 3)
		return (va_arg(ap, long));
	else if (res->len == 4)
		return (va_arg(ap, long long));
	else if (res->len == 5)
		return ((size_t)va_arg(ap, size_t));
	else if (res->len == 6)
		return ((intmax_t)va_arg(ap, intmax_t));
	else
		return (va_arg(ap, int));
}

void					dec_conv(char **format, t_plchdr *res, va_list ap)
{
	intmax_t		nbr;
	char				*s;

	if (**format == 'D')
		res->len = 3;
	nbr = get_int(res, ap);
	res->neg = (nbr < 0) ? -1 : 1;
	s = ft_itoa(nbr);
	if (res->width == 0)
		res->size += ft_strlen(s);
	else if (res->width < (intmax_t)ft_strlen(s))
		res->size = ft_strlen(s);
	put_width_spc(format, s, res);
	ft_strdel(&s);
}

char					*base_conv(t_plchdr *res, va_list ap)
{
	if (res->len == 1)
		return (ft_u_itoa_bs((unsigned char)va_arg(ap, unsigned int), res->base));
	else if (res->len == 2)
		return (ft_u_itoa_bs((unsigned short)va_arg(ap, unsigned int), res->base));
	else if (res->len == 3)
		return (ft_u_itoa_bs(va_arg(ap, unsigned long), res->base));
	else if (res->len == 4)
		return (ft_u_itoa_bs(va_arg(ap, unsigned long long), res->base));
	else if (res->len == 5)
		return (ft_u_itoa_bs((size_t)va_arg(ap, size_t), res->base));
	else if (res->len == 6)
		return (ft_u_itoa_bs((intmax_t)va_arg(ap, uintmax_t), res->base));
	else
		return (ft_u_itoa_bs(va_arg(ap, unsigned int), res->base));
}
