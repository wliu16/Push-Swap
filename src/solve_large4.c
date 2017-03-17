/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_large4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:15:00 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:36:46 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//push b back to a

static int	ind_to_pb_helper(t_stack *s)
{
	int		i;
	int		b;
	int		a;

	i = 0;
	a = (s->a)[0];
	b = (s->b)[0];
	while (i < s->size_a)
	{
		if (b < (s->a)[i] && a > (s->a)[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	find_ind_to_pb(t_stack *s)
{
	int		i;
	int		index;

	calc_max_min(s);
	if ((index = ind_to_pb_helper(s)) != -1)
		return (index);
	if ((s->b)[0] > s->a_max || (s->b)[0] < s->a_min)
		return (s->a_min_ind);
	i = 0;
	while (i < s->size_a - 1)
	{
		if ((s->b)[0] < (s->a)[i])
			return (i);
		else if ((s->b)[0] > (s->a)[i] && (s->b)[0] < (s->a)[i + 1])
			return (i + 1);
		i++;
	}
	return (0);
}

void		push_b_to_a(t_stack *s)
{
	int pos;

	while (s->size_b)
	{
		pos = find_ind_to_pb(s);
		to_top_a(s, pos);
		op_push(s, 'a', 1);
	}
	calc_max_min(s);
	to_top_a(s, s->a_min_ind);
}
