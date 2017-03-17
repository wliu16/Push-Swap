/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:29:36 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 15:14:08 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		res++;
	}
	return (res);
}

static char		*getword(char const *s, size_t start, size_t end)
{
	char	*res;
	size_t	i;

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

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**res;
	size_t	start;
	size_t	j;

	if (s == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (!s[j])
			break ;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		res[i++] = getword(s, start, j - 1);
	}
	res[i] = 0;
	return (res);
}
