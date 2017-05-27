/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 10:02:38 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/20 11:56:20 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(intmax_t n)
{
	char		*str;
	intmax_t	num;
	size_t		len;

	len = ft_count_int_len(n, 10);
	num = n;
	str = (char*)malloc(len);
	if (!str)
		return (0);
	len--;
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
