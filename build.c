#include "ft_printf.h"

t_plchdr init_res(intmax_t size)
{
	t_plchdr	res;

	res = *(t_plchdr*)malloc(sizeof(t_plchdr));
	res.s_str = ft_strnew(size);
	res.res = ft_strnew(size);
	res.size = size;
	res.len = 0;
	return (res);
}

void	append_str(char *s, char c)
{
	int len;

	len = ft_strlen(s);
	s[len] = c;
	s[len + 1] = '\0';
}
