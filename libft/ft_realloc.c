/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:23:05 by wliu              #+#    #+#             */
/*   Updated: 2017/01/25 15:20:36 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include <stdlib.h>

char	*ft_realloc(char *old_str, size_t old_size, size_t new_size)
{
	char	*new_str;
	size_t	i;

	new_str = ft_strnew(new_size);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_str[i] = old_str[i];
		i++;
	}
	free(old_str);
	return (new_str);
}
