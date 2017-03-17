/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:27:59 by wliu              #+#    #+#             */
/*   Updated: 2016/12/21 11:18:34 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		split_buf(char **buf, char **line, t_lst **cur, int *num)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;

	(*num)++;
	i = -1;
	while ((*buf)[++i])
		if ((*buf)[i] == '\n')
			break ;
	tmp2 = ft_strnew(i);
	ft_strncpy(tmp2, *buf, i);
	tmp1 = ft_strjoin(*line, tmp2);
	ft_strdel(&tmp2);
	if (*line != NULL)
		ft_strdel(line);
	*line = tmp1;
	if (i > ft_strlen(*buf) - 1)
	{
		ft_strclr(*buf);
		return (0);
	}
	(*cur)->tmp = ft_strdup(*buf + i + 1);
	(*cur)->size = ft_strlen(*buf) - i - 1;
	ft_strclr(*buf);
	return (1);
}

static int		split_tmp(char **line, t_lst **cur)
{
	int		i;
	char	*tmp2;

	i = -1;
	while (++i < (*cur)->size)
		if (((*cur)->tmp)[i] == '\n')
			break ;
	if (i == (*cur)->size)
	{
		*line = (*cur)->tmp;
		(*cur)->size = 0;
		return (0);
	}
	*line = ft_strnew(i);
	ft_strncpy(*line, (*cur)->tmp, i);
	if (i == (*cur)->size - 1)
		ft_strdel(&((*cur)->tmp));
	else
	{
		tmp2 = ft_strdup((*cur)->tmp + i + 1);
		ft_strdel(&((*cur)->tmp));
		(*cur)->tmp = tmp2;
	}
	(*cur)->size -= i + 1;
	return (1);
}

static void		rem_cur(const int fd, t_lst **begin)
{
	t_lst	dummy;
	t_lst	*prev;
	t_lst	*cur;
	t_lst	*nxt;

	dummy.next = *begin;
	prev = &dummy;
	while (prev->next)
	{
		cur = prev->next;
		nxt = cur->next;
		if (cur->fd == fd)
		{
			if (nxt != NULL)
				prev->next = nxt;
			else
				prev->next = NULL;
			free(cur);
			break ;
		}
		prev = cur;
	}
	*begin = dummy.next;
}

static t_lst	*get_cur(const int fd, t_lst **begin)
{
	t_lst	dummy;
	t_lst	*beg;
	t_lst	*new;

	dummy.next = *begin;
	dummy.fd = -1;
	beg = &dummy;
	while (beg)
	{
		if (beg->fd == fd)
			return (beg);
		if (beg->next == NULL)
			break ;
		beg = beg->next;
	}
	new = (t_lst *)malloc(sizeof(t_lst));
	new->tmp = NULL;
	new->fd = fd;
	new->size = 0;
	new->next = NULL;
	beg->next = new;
	*begin = dummy.next;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	char			*buf;
	static t_lst	*begin = 0;
	t_lst			*cur;
	int				ret;
	int				i;

	if (fd == -1 || line == NULL)
		return (-1);
	cur = get_cur(fd, &begin);
	i = cur->size;
	*line = NULL;
	if (cur->tmp && split_tmp(line, &cur))
		return (1);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		if (split_buf(&buf, line, &cur, &i))
			break ;
	ft_strdel(&buf);
	if (ret == -1)
		return (-1);
	if (i > 0)
		return (1);
	rem_cur(fd, &begin);
	return (0);
}
