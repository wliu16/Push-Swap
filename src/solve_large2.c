/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_large2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:14:30 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:35:46 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//f_heuristic
//given index_a, calculate op_num_a[index_a] and op_num_b[index_a] (+: shift up, -:down)
//min # of steps to make a[index_a] to top of a, and right position for a[index_a] to top of b

static void	count_steps_b(t_stack *s, int a, int *b_up, int *b_down)
{
	int i;

	calc_max_min(s);
	if (a > s->b_max || a < s->b_min)
	{
		*b_up = steps_to_top(s->b_max_ind, s->size_b, 'u');
		*b_down = steps_to_top(s->b_max_ind, s->size_b, 'd');
	}
	else if (a > (s->b)[0] && a < (s->b)[s->size_b - 1])
	{
		*b_up = 0;
		*b_down = s->size_b;
	}
	else
	{
		i = 0;
		while (++i < s->size_b)
		{
			if (a > (s->b)[i] && a < (s->b)[i - 1])
			{
				*b_up = steps_to_top(i, s->size_b, 'u');
				*b_down = steps_to_top(i, s->size_b, 'd');
			}
		}
	}
}

static int	helper1(t_stack *s, int index_a, int a_down, int b_down)
{
	int res;

	res = abs(a_down - b_down);
	s->op_num_a[index_a] = -a_down;
	s->op_num_b[index_a] = -b_down;
	return (res);
}

static int	helper2(t_stack *s, int index_a, int a_up, int b_down)
{
	int res;

	res = a_up + b_down;
	s->op_num_a[index_a] = a_up;
	s->op_num_b[index_a] = -b_down;
	return (res);
}

static int	helper3(t_stack *s, int index_a, int a_down, int b_up)
{
	int res;

	res = a_down + b_up;
	s->op_num_a[index_a] = -a_down;
	s->op_num_b[index_a] = b_up;
	return (res);
}

void		f_heuristic(t_stack *s, int index_a)
{
	int a_up;
	int a_down;
	int b_up;
	int b_down;
	int res;

	a_up = steps_to_top(index_a, s->size_a, 'u');
	a_down = steps_to_top(index_a, s->size_a, 'd');
	count_steps_b(s, (s->a)[index_a], &b_up, &b_down);
	res = abs(a_up - b_up);
	s->op_num_a[index_a] = a_up;
	s->op_num_b[index_a] = b_up;
	if (abs(a_down - b_down) <= res)
		res = helper1(s, index_a, a_down, b_down);
	if (a_up + b_down <= res)
		res = helper2(s, index_a, a_up, b_down);
	if (a_down + b_up <= res)
		res = helper3(s, index_a, a_down, b_up);
}
