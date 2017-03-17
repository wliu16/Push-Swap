/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:32:09 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 15:46:07 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	if (lst == NULL || f(lst) == NULL)
		return (NULL);
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp = f(lst);
	res = tmp;
	while (lst)
	{
		if (tmp == NULL)
			return (NULL);
		lst = lst->next;
		if (lst == NULL)
			tmp->next = NULL;
		else
		{
			tmp->next = (t_list *)malloc(sizeof(t_list));
			tmp->next = f(lst);
			tmp = tmp->next;
		}
	}
	return (res);
}
