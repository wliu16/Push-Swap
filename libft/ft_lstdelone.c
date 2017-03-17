/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:45:50 by wliu              #+#    #+#             */
/*   Updated: 2016/12/06 10:45:53 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	while (alst == NULL)
		return ;
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void *)alst);
	}
}
