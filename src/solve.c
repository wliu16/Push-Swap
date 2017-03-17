/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:59:33 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:32:12 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//solve
//solve_3
//solve_5

void		solve_3(t_stack *s)
{
	int a1;
	int a2;
	int a3;

	a1 = s->a[0];
	a2 = s->a[1];
	a3 = s->a[2];
	if (is_sort(s->a, s->size_a))
		return ;
	if (a1 < a2 && a1 < a3)
	{
		op_swap(s, 'a', 1);
		op_rotate(s, 'a', 1);
	}
	else if (a2 < a1 && a1 < a3)
		op_swap(s, 'a', 1);
	else if (a2 < a3 && a3 < a1)
		op_rotate(s, 'a', 1);
	else if (a3 < a1 && a1 < a2)
		op_reverse(s, 'a', 1);
	else if (a3 < a2 && a2 < a1)
	{
		op_swap(s, 'a', 1);
		op_reverse(s, 'a', 1);
	}
}

static void	push_to_a(t_stack *s, int b_top, int i)
{
	calc_max_min(s);
	if (b_top > s->a_max || b_top < s->a_min)
	{
		while (s->a_min_ind <= 2 && s->a_min_ind > 0 && (s->a_min_ind)--)
			op_rotate(s, 'a', 1);
		if (s->a_min_ind == 3)
			op_reverse(s, 'a', 1);
		op_push(s, 'a', 1);
		return ;
	}
	i = 0;
	while (++i < 4)
	{
		if (b_top > (s->a)[i - 1] && b_top < (s->a)[i])
		{
			while (i <= 2 && i > 0 && i--)
				op_rotate(s, 'a', 1);
			if (i == 3)
				op_reverse(s, 'a', 1);
			op_push(s, 'a', 1);
			return ;
		}
	}
	op_push(s, 'a', 1);
}

void		solve_5(t_stack *s)
{
	int i;

	i = 0;
	while (s->size_a > 3)
		op_push(s, 'b', 1);
	solve_3(s);
	if ((s->b)[0] < (s->a)[0] || (s->b)[0] > (s->a)[2])
		op_push(s, 'a', 1);
	else
	{
		if ((s->b)[0] > (s->a)[0] && (s->b)[0] < (s->a)[1])
			op_rotate(s, 'a', 1);
		else
			op_reverse(s, 'a', 1);
		op_push(s, 'a', 1);
	}
	if (s->size_b)
		push_to_a(s, (s->b)[0], i);
}

void		to_top_a(t_stack *s, int index)
{
	int	min_step;
	int	up;
	int	down;

	up = steps_to_top(index, s->size_a, 'u');
	down = steps_to_top(index, s->size_a, 'd');
	min_step = min_2(up, down);
	while (min_step)
	{
		if (up < down)
			op_rotate(s, 'a', 1);
		else
			op_reverse(s, 'a', 1);
		min_step--;
	}
}

void		solve(t_stack *s)
{
	if (s->size_a == 2)
		op_swap(s, 'a', 1);
	else if (s->size_a == 3)
		solve_3(s);
	else if (s->size_a <= 5)
		solve_5(s);
	else
		solve_large(s);
	if (!is_sort(s->a, s->size_a))
	{
		calc_max_min(s);
		to_top_a(s, s->a_min_ind);
	}
}
