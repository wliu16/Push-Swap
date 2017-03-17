/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:24:07 by wliu              #+#    #+#             */
/*   Updated: 2016/12/05 12:46:32 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	res = (void *)malloc(size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)res)[i] = 0;
		i++;
	}
	return (res);
}
