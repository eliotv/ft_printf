#include "ft_printf.h"

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
	if (*(*format) == 'o')
		ft_putchar('0');
	if (*(*format) == 'x')
		ft_putstr("0x");
	if (*(*format) == 'X')
		ft_putstr("0X");
}
