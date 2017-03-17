/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:31:49 by wliu              #+#    #+#             */
/*   Updated: 2016/11/30 15:58:07 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char		*ft_strstr(const char *big, const char *little)
{
	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		if (*little == *big)
		{
			if (check(little, big))
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
