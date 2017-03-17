/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:12:31 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:29:22 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//main for push_swap

int			main(int ac, char **av)
{
	t_stack	*s;

	if (ac == 1)
		return (0);
	s = create_stack(ac, av);
	if (!s)
		return (error());
	if (!is_sort(s->a, s->size_a))
		solve(s);
	free_stack(s);
	return (1);
}
