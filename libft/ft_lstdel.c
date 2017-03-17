/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:44:39 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 15:26:19 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur_next;

	if (alst == NULL)
		return ;
	while (*alst != NULL)
	{
		cur_next = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = cur_next;
	}
}
