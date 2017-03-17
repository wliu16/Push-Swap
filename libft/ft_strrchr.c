/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:54:57 by wliu              #+#    #+#             */
/*   Updated: 2016/12/22 15:29:02 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;

	ss = (char *)s;
	while (*ss)
		ss++;
	if (c == 0)
		return (ss);
	ss--;
	while (ss >= s && *ss)
	{
		if (*ss == c)
			return (ss);
		ss--;
	}
	return (NULL);
}
