/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:00:37 by wliu              #+#    #+#             */
/*   Updated: 2017/01/30 12:58:26 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			res_ok(t_stack *s)
{
	ft_putstr_fd("OK\n", 1);
	free_stack(s);
	return (0);
}

int			res_ko(t_stack *s)
{
	ft_putstr_fd("KO\n", 1);
	free_stack(s);
	return (0);
}

int			error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}
