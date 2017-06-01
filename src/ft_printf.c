/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:25 by evanheum          #+#    #+#             */
/*   Updated: 2017/05/31 21:19:19 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	search_flg_mod(char **format, va_list ap, t_plchdr *res)
{
	if (FLG_MOD)
		flag_finder(format, res);
	if (NUM_MOD)
		get_width_len(format, res);
	if (**format == '.')
		perc_num(format, res, ap);
	if (**format == '*')
		width_mod(format, ap, res);
	if (!F_SPEC)
		length_mod_ck(format, res);
}

void	search_format(char **format, va_list ap, t_plchdr *res)
{
	int i;

	i = 0;
	while (**format)
	{
		while (**format == '%')
		{
			i += res->size;
			res = init_res(res);
			(*format)++;
			while ((FLG_MOD || NUM_MOD || **format == '.' || **format == '*' || L_MOD) && **format)
				search_flg_mod(format, ap, res);
			if (F_SPEC)
				function_hndlr(format, ap, res);
		}
		(**format) ? ft_putchar(**format) : 0;
		if (**format && **format != '%')
		{
			res->size++;
			(*format)++;
		}
	}
	res->size += i;
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	t_plchdr *res;
	int i;

	res = NULL;
	res = init_res(res);
	va_start(ap, format);
	search_format((char**)&format, ap, res);
	va_end(ap);
	i = res->size;
	free(res);
	return (i);
}
