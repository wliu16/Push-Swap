/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:19:18 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 12:05:25 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	src_len;
	size_t	dst_len;
	size_t	index;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index = dst_len;
	while (size >= 1 && index < size - 1)
	{
		dst[index] = src[i];
		index++;
		i++;
	}
	dst[index] = '\0';
	if (size < dst_len)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
