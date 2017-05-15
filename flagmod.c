#include "ft_printf.h"

void	flag_finder(char **format, t_plchdr *res)
{
	if (*(*format) == '-')
	{
		res->p_n = -1;
		(*format)++;
	}
	else if (*(*format) == '+')
	{
		res->p_n = 2;
		(*format)++;
	}

}
