#include "libftprintf.h"

void	flag_finder(char **format, t_plchdr *res)
{
		if (**format == '#')
		{
			(*format)++;
			res->hash = 1;
		}
		if (**format == '-')
		{	
			res->minus = 1;
			(*format)++;
			if (*(*format) == '+')
			{
				res->plus = 1;
				(*format)++;
			}
		}
		if (**format == '+')
		{
			res->plus = 1;
			(*format)++;
			if (**format == '+')
				(*format)++;
			if (**format =='-')
			{	
				res->minus = 1;
				(*format)++;
			}
		}
		if (**format == '0' && res->plus == 1 && res->minus == 0)
		{
			res->k = '0';
			(*format)++;
		}
		else if (**format == '0')
			(*format)++;
		if (**format == ' ')
		{
			res->k = ' ';
			(**format)++;
		}
}

void hash_handler(char **format, t_plchdr *res)
{
	if ((**format == 'o' && res->p == 1) || (**format == 'o' && res->hash == 1))
		ft_putchar('0');
	if ((**format == 'x' && res->p == 1) || (**format == 'x' && res->hash == 1))
		ft_putstr("0x");
	if ((**format == 'X' && res->p == 1) || (**format == 'X' && res->hash == 1))
		ft_putstr("0X");
}
