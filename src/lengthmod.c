/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengthmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:28 by evanheum          #+#    #+#             */
/*   Updated: 2017/05/28 12:31:59 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char length_mod_ck(char **format, t_plchdr *res)
{
	if (!F_SPEC)
	{
		if(**format == 'h' && res->len < 2)
		{
			res->len = 2;
			(*format)++;
			if(*(*format) == 'h')
			{
				res->len = 1;
				(*format)++;
			}
		}
		if (res->len < 3 && **format == 'l')
		{
			res->len = 3;
			(*format)++;
			if (*(*format) == 'l')
			{
				res->len = 4;
				(*format)++;
			}
		}
		if (res->len < 5 && **format == 'z')
		{
			res->len = 5;
			(*format)++;
		}
		if (res->len < 6 && **format == 'j')
		{
			res->len = 6;
			(*format)++;
		}
	}
	return (**format);
}
