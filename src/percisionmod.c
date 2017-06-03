/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percisionmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:33 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/02 20:33:07 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	**perc_num(char **format, t_plchdr *res, va_list ap)
{
	res->p = 1;
	res->k = ' ';
	(*format)++;
	if (*(*format) == '*')
	{
		(*format)++;
		width_mod(format, ap, res);
	}
	if (NUM_MOD)
		perc_width(format, res);
	return (format);
}

void	put_perc(char **format, char *str, t_plchdr *res)
{
	intmax_t i;
	intmax_t n;

	i = 0;
	n = ft_strlen(str);
	if (**format != 's')
	{
		if (i < res->p_width && str[i])
			write(1, &str[i], n);
	}
	else
		while (i < res->p_width && str[i])
			write(1, &str[i++], 1);
}

int		percision_mod(char **format, t_plchdr *res, char *s, int n)
{
	char *tmp;

	tmp = NULL;
	if (**format == 's')
	{
		tmp = ft_strndup(s, res->p_width);
		n = ft_strlen(tmp);
	}
	if (res->plus == 1 && res->minus == 0)
	{
		n = res->p_width - 1;
		if (res->hash == 0)
			res->width--;
	}
	else if (n < 0)
		n = res->p_width;
	return (n);
}
