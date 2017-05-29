/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percisionmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:33 by evanheum          #+#    #+#             */
/*   Updated: 2017/05/28 19:05:54 by evanheum         ###   ########.fr       */
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
