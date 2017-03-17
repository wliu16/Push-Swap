/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:47:46 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 12:08:59 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getsize(int n)
{
	size_t res;

	res = 1;
	while (n > 9)
	{
		res *= 10;
		n /= 10;
	}
	return (res);
}

void			ft_putnbr(int n)
{
	size_t size;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0 && n > -2147483648)
	{
		ft_putchar('-');
		n = -n;
	}
	size = getsize(n);
	while (size > 0)
	{
		ft_putchar(n / size % 10 + '0');
		size /= 10;
	}
}
