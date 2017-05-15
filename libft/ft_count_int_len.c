/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_int_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:45:04 by evanheum          #+#    #+#             */
/*   Updated: 2017/03/20 11:46:41 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_int_len(long long n, int base)
{
	size_t	i;

	i = 2;
	if (n == 0)
	{
		n = 0;
		return (i);
	}
	if (n < 0)
		i++;
	while (n /= base)
		i++;
	return (i);
}
