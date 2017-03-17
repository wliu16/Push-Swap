/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:46:29 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 12:11:51 by wliu             ###   ########.fr       */
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

void			ft_putnbr_fd(int n, int fd)
{
	size_t size;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0 && n > -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	size = getsize(n);
	while (size > 0)
	{
		ft_putchar_fd(n / size % 10 + '0', fd);
		size /= 10;
	}
}
