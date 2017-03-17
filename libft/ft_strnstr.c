/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:31:49 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 10:57:22 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	check(const char *little, const char *big)
{
	while (*little)
	{
		if (*big != *little)
			return (0);
		little++;
		big++;
	}
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	end;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	end = len - ft_strlen(little);
	while (*big && i <= end)
	{
		if (*little == *big)
		{
			if (check(little, big))
				return ((char *)big);
		}
		big++;
		i++;
	}
	return (NULL);
}
