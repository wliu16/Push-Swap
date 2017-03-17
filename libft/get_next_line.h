/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:25:52 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 11:43:14 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 10

typedef struct	s_lst
{
	int				fd;
	char			*tmp;
	int				size;
	struct s_lst	*next;
}				t_lst;

int				get_next_line(const int fd, char **line);

#endif
