/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_large3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:13:40 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:36:29 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//push a[i] to stack b

static void	rot_rot(t_stack *s, int i)
{
	while (s->op_num_a[i] > 0 && s->op_num_b[i] > 0)
	{
		op_rotate_ab(s, 1);
		s->op_num_a[i] -= 1;
		s->op_num_b[i] -= 1;
	}
	while (s->op_num_a[i] > 0)
	{
		op_rotate(s, 'a', 1);
		s->op_num_a[i] -= 1;
	}
	while (s->op_num_b[i] > 0)
	{
		op_rotate(s, 'b', 1);
		s->op_num_b[i] -= 1;
	}
}

static void	rev_rev(t_stack *s, int i)
{
	while (s->op_num_a[i] < 0 && s->op_num_b[i] < 0)
	{
		op_reverse_ab(s, 1);
		s->op_num_a[i] += 1;
		s->op_num_b[i] += 1;
	}
	while (s->op_num_a[i] < 0)
	{
		op_reverse(s, 'a', 1);
		s->op_num_a[i] += 1;
	}
	while (s->op_num_b[i] < 0)
	{
		op_reverse(s, 'b', 1);
		s->op_num_b[i] += 1;
	}
}

static void	rot_rev(t_stack *s, int i)
{
	while (s->op_num_a[i] > 0)
	{
		op_rotate(s, 'a', 1);
		s->op_num_a[i] -= 1;
	}
	while (s->op_num_b[i] < 0)
	{
		op_reverse(s, 'b', 1);
		s->op_num_b[i] += 1;
	}
}

static void	rev_rot(t_stack *s, int i)
{
	while (s->op_num_a[i] < 0)
	{
		op_reverse(s, 'a', 1);
		s->op_num_a[i] += 1;
	}
	while (s->op_num_b[i] > 0)
	{
		op_rotate(s, 'b', 1);
		s->op_num_b[i] -= 1;
	}
}

void		push_to_stack(t_stack *s, char to_stack, int i)
{
	if (s->op_num_a[i] > 0 && s->op_num_b[i] > 0)
		rot_rot(s, i);
	else if (s->op_num_a[i] < 0 && s->op_num_b[i] < 0)
		rev_rev(s, i);
	else if (s->op_num_a[i] >= 0 && s->op_num_b[i] <= 0)
		rot_rev(s, i);
	else if (s->op_num_a[i] <= 0 && s->op_num_b[i] >= 0)
		rev_rot(s, i);
	if (to_stack == 'a')
		op_push(s, 'a', 1);
	else
		op_push(s, 'b', 1);
}
