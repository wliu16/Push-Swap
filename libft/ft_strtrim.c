/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:57:04 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 12:23:39 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	find_index(char const *s, int *start, int *end)
{
	*end = ft_strlen(s) - 1;
	while (*end >= 0 && (s[*end] == ' ' || s[*end] == '\n' || s[*end] == '\t'))
		(*end)--;
	*start = 0;
	while (s[*start] && (s[*start] == ' ' ||
				s[*start] == '\n' || s[*start] == '\t'))
		(*start)++;
}

char		*ft_strtrim(char const *s)
{
	int		end;
	int		start;
	size_t	i;
	char	*res;

	if (s == NULL)
		return (NULL);
	find_index(s, &start, &end);
	if (start > end)
	{
		res = ft_strnew(0);
		return (res);
	}
	res = ft_strnew(end - start + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
