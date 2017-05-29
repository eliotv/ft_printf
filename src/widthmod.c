/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widthmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:33:35 by evanheum          #+#    #+#             */
/*   Updated: 2017/05/28 17:43:49 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	width_mod(char **format, va_list ap, t_plchdr *res)
{
	res->width = va_arg(ap, intmax_t);
	(*format)++;
}

void put_width_spc(char **format, char *s, t_plchdr *res)
{
	intmax_t n;
	char *tmp;

	tmp = NULL;
	n = ft_strlen(s);
	if (n == 0)
		res->p_width = 0;
	if (res->p == 1)
	{
		if (**format == 's')
		{
			tmp = ft_strndup(s, res->p_width);
			n = ft_strlen(tmp);
		}
		if (res->plus == 1 && res->minus == 0)
		{
			n = res->p_width - 1;
			if(res->hash == 0)
				res->width--;
		}
		else if (n < 0)
			n = res->p_width;
	}
	if (n < res->width && res->minus == 1)
	{
		if (res->hash == 1)
		{
			hash_handler(format, res);
			if (**format == 'x' || **format == 'X' || **format == 'o')
				res->width--;
			if (**format == 'x' || **format == 'X')
				res->width--;
		}
		if (res->plus == 1 &&  res->p == 0 && res->neg == 1)
		{
			ft_putchar('+');
			res->width--;
		}
		if (DIG_MOD)
		{
			if (res->p_width > res->width)
				res->size += res->p_width - res->width;
			while(res->p_width-- > n)
			{
				ft_putchar('0');
				res->width--;
			}
		}
		if (res->p == 1)
			put_perc(format, s, res);
		else
			ft_putstr(s);
		while(n < res->width--)
			ft_putstr(&res->k);
	}
	else if (n < res->width && res->plus == 1)
	{
		if (res->k == '0' && *s != '-')
			ft_putchar('+');
		else if (*s == '-')
		{
			ft_putchar(*s);
			s++;
		}
		if ((res->hash == 1 && res->p == 1) || (res->plus == 1 && res->neg == 1))
			res->width--;
		if (res->hash == 1 &&((**format == 'o') || (**format == 'x') || (**format == 'X')))
			res->width--;
		while(n < res->width--)
		{
			ft_putstr(&res->k);
			if (res->width == res->p_width)
				break ;
		}
		if (res->hash == 1)
			hash_handler(format, res);
		if (res->k == ' ' && res->plus == 1 && res->neg != -1 && **format == 'd')
			ft_putchar('+');
		if (res->p_width == res->width)
			ft_putchar('0');
		if (res->p == 1)
			put_perc(format, s, res);
		else
			ft_putstr(s);
	}
	else if (n < res->width)
	{

		if (res->hash == 1 && res->p == 0 && **format != 's' && (**format != 'd' || **format != 'i') && **format != 'o')
			res->width--;
		if (res->hash == 1 && ((**format == 'o') || (**format == 'x') || (**format == 'X')))
			res->width--;
		if (res->plus == 1 && res->hash == 0)
			ft_putchar('+');
		if (*s == '-' && res->k == '0')
		{
			ft_putchar(*s);
			s++;
		}
		if (res->k == '0')
			hash_handler(format, res);
		if (n < res->p_width)
		{
			res->k = ' ';
			while (res->p_width < res->width--)
				ft_putstr(&res->k);
			res->size--;
		}
		else
			while (n < res->width)
			{
				ft_putstr(&res->k);
				res->width--;
			}
		if (DIG_MOD)
		{
			if (res->p_width > res->width)
				res->size += res->p_width - res->width;
			while (res->p_width-- > n)
				ft_putchar('0');
		}
		if (res->k == ' ')
			hash_handler(format, res);
		if (res->p == 1)
			put_perc(format, s, res);
		else if (res->p_width == -1  && *s == '0' && res->hash == 0)
			ft_putchar(' ');
		else
			ft_putstr(s);
	}
	else
	{
		if(res->plus == 1 && *s != '-' && **format != 'u')
		{
			ft_putchar('+');
			res->size++;
		}
		if (res->hash == 1 && *s != '0')
			hash_handler(format, res);
		if (*s == '0' && res->p == 1 && **format != 'o' && res->hash == 1)
			NULL;
		if (DIG_MOD)
		{
			while (res->p_width > n)
			{
				if (*s == '-')
				{
					ft_putchar(*s);
					s++;
					res->size++;
					ft_putchar('0');
				}
				++res->size;
				res->p_width--;
				ft_putchar('0');
			}
		}
		space_flag(format, s, res);
		if ((**format == 'u' || **format == 'U') && res->width > 1)
				res->size = ft_strlen(s);
		if (res->p == 1 && res->p_width > 0)
			put_perc(format, s, res);
		else if (res->p == 1 && res->p_width <= 0 && *s == '0')
		{
			if (**format == 'o' && res->hash == 1)
				ft_putstr(s);
			else
			{
				if (res->hash == 1)
					NULL;
				res->size--;
				NULL;
			}
		}
		else
			ft_putstr(s);


	}
}

char **get_width_len(char **format, t_plchdr *res)
{
	res->width = ft_atoi(*format);
	res->size += res->width;
	while (!F_SPEC)
	{
		if (**format == '.')
		{
			res->p = 1;
			(*format)++;
			res->p_width = ft_atoi(*format);
		}
		else
			(*format)++;
	}
	if (**format != 's')
		res->p = 0;
	return (format);
}

char **perc_width(char **format, t_plchdr *res)
{
	res->p_width = ft_atoi(*format);
	while (!F_SPEC)
		(*format)++;
	if (**format != 's' && **format != 'd' && **format != 'o' && **format != 'x')
		res->p = 0;
	return (format);
}

/*void put_str(char *str, int len)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], len);
}*/
