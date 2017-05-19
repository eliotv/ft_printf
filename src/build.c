#include "libftprintf.h"

t_plchdr *init_res(t_plchdr *res)
{
	if (res != NULL)
		free (res);
	res = (t_plchdr*)malloc(sizeof(t_plchdr));
	res->len = 0;
	res->width = 0;
	res->plus = 0;
	res->k = ' ';
	res->p = 0;
	res->p_width = 0;
	res->hash = 0;
	res->minus = 0;
	res->neg = 0;
	res->size = 0;
	res->base = 0;
	res->s_str = malloc(sizeof(25));
	return (res);
}
