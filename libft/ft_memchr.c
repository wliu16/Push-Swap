/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:02:14 by wliu              #+#    #+#             */
/*   Updated: 2016/12/05 11:58:36 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;

	uc = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == uc)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
