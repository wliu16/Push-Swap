/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:55:48 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 12:20:00 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*print(int n)
{
	char	*res;

	if (n == 0)
	{
		res = ft_strnew(1);
		res[0] = '0';
	}
	else
	{
		res = ft_strnew(11);
		res[0] = '-';
		res[1] = '2';
		res[2] = '1';
		res[3] = '4';
		res[4] = '7';
		res[5] = '4';
		res[6] = '8';
		res[7] = '3';
		res[8] = '6';
		res[9] = '4';
		res[10] = '8';
	}
	return (res);
}

static int	getsize(int n)
{
	int	neg;
	int	res;

	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	else
		neg = 0;
	res = 1;
	while (n > 9)
	{
		res++;
		n /= 10;
	}
	return (res + neg);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*res;

	if (n == -2147483648 || n == 0)
		return (print(n));
	size = getsize(n);
	if (n < 0)
		n = -n;
	res = ft_strnew(size);
	if (res == NULL)
		return (NULL);
	size--;
	while (size >= 0 && n > 0)
	{
		res[size] = n % 10 + '0';
		n /= 10;
		size--;
	}
	if (size == 0)
		res[size] = '-';
	return (res);
}
