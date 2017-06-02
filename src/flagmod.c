/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:15 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/01 20:42:30 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void 	hash_handler(char **format, t_plchdr *res)
{
	if (((**format == 'o' || **format == 'O') && res->p == 1) || ((**format == 'o' || **format == 'O') && res->hash == 1))
	{
		if (res->width == 0)
			res->size++;
		ft_putchar('0');
	}
	if ((**format == 'x' && res->p == 1) || (**format == 'x' && res->hash == 1))
	{
		if (res->width == 0)
			res->size = res->size + 2;
		ft_putstr("0x");
	}
	if ((**format == 'X' && res->p == 1) || (**format == 'X' && res->hash == 1))
	{
		if (res->width == 0)
			res->size = res->size + 2;
		ft_putstr("0X");
	}
}

char	**minus_flag(char **format, t_plchdr *res)
{
	res->minus = 1;
	(*format)++;
	if (**format == '+')
	{
		res->plus = 1;
		(*format)++;
	}
	return (format);
}

char	**plus_flag(char **format, t_plchdr *res)
{
	res->plus = 1;
	(*format)++;
	if (**format == '+')
		(*format)++;
	if (**format == '-')
	{
		res->minus = 1;
		(*format)++;
	}
	return (format);
}

char	**zero_flag(char **format, t_plchdr *res)
{
	if (**format == '0' && res->minus == 0)
	{
		res->k = '0';
		(*format)++;
	}
	else if (**format == '0')
		(*format)++;
	return (format);
}

void	space_flag(char **format, char *s, t_plchdr *res)
{
	if (res->minus == 0 && *s != '-' && res->sf == 1 && (**format == 'd' || **format == 'i' )&& res->plus == 0)
	{
		res->size++;
		ft_putchar(' ');
	}
}
