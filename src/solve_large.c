/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:13:47 by wliu              #+#    #+#             */
/*   Updated: 2017/02/11 10:16:33 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			steps_to_top(int index, int size, char up_down)
{
	if (up_down == 'u')
		return (index);
	else
		return (size - index);
}

int			get_min_steps(t_stack *s, int size)
{
	int	min_index;
	int	*sum_steps;
	int	i;

	sum_steps = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		if ((s->op_num_a)[i] >= 0 && (s->op_num_b)[i] >= 0)
			sum_steps[i] = max_2((s->op_num_a)[i], (s->op_num_b)[i]);
		else if ((s->op_num_a)[i] <= 0 && (s->op_num_b)[i] <= 0)
			sum_steps[i] = abs(min_2((s->op_num_a)[i], (s->op_num_b)[i]));
		else
			sum_steps[i] = abs((s->op_num_a)[i] - (s->op_num_b)[i]);
		i++;
	}
	min_index = arr_min_index(sum_steps, size);
	free(sum_steps);
	return (min_index);
}

static void	final_sort_a(t_stack *s)
{
	int	steps_up;
	int	steps_down;
	int	steps_to_sort;

	calc_max_min(s);
	steps_up = steps_to_top(s->a_min_ind, s->size_a, 'u');
	steps_down = steps_to_top(s->a_min_ind, s->size_a, 'd');
	if (steps_up < steps_down)
		steps_to_sort = steps_up;
	else
		steps_to_sort = -steps_down;
	while (steps_to_sort > 0)
	{
		op_rotate(s, 'a', 1);
		steps_to_sort--;
	}
	while (steps_to_sort < 0)
	{
		op_reverse(s, 'a', 1);
		steps_to_sort++;
	}
}

void		solve_large(t_stack *s)
{
	int index_a;
	int ind_a_push;

	op_push(s, 'b', 1);
	op_push(s, 'b', 1);
	while (s->size_a > 5)
	{
		index_a = 0;
		while (index_a < s->size_a)
		{
			f_heuristic(s, index_a);
			index_a++;
		}
		ind_a_push = get_min_steps(s, s->size_a);
		push_to_stack(s, 'b', ind_a_push);
	}
	solve_5(s);
	push_b_to_a(s);
	final_sort_a(s);
}
