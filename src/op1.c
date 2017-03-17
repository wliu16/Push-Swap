/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:39:46 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:30:33 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//operations for one stack (a or b)
//sa, sb, ra, rb, rra, rrb, pa, pb

void		op_swap(t_stack *s, char stack, bool print)
{
	int **cur_stk;
	int tmp;

	if ((stack == 'a' && s->size_a >= 2)
		|| (stack == 'b' && s->size_b >= 2))
	{
		if (stack == 'a')
			cur_stk = &(s->a);
		else
			cur_stk = &(s->b);
		tmp = (*cur_stk)[0];
		(*cur_stk)[0] = (*cur_stk)[1];
		(*cur_stk)[1] = tmp;
	}
	if (print)
		ft_printf("s%c\n", stack);
	if (s->flag_v)
	{
		if (print == 0)
			ft_printf("------\ns%c\n", stack);
		print_stack(s);
	}
}

void		op_push(t_stack *s, char to_stack, bool print)
{
	int tmp;

	if (to_stack == 'a' && s->size_b > 0)
	{
		tmp = pop(&(s->b), s->size_b);
		push(&(s->a), tmp, s->size_a);
		s->size_a++;
		s->size_b--;
	}
	else if (to_stack == 'b' && s->size_a > 0)
	{
		tmp = pop(&(s->a), s->size_a);
		push(&(s->b), tmp, s->size_b);
		s->size_a--;
		s->size_b++;
	}
	if (print)
		ft_printf("p%c\n", to_stack);
	if (s->flag_v)
	{
		if (print == 0)
			ft_printf("------\np%c\n", to_stack);
		print_stack(s);
	}
}

void		op_rotate(t_stack *s, char stack, bool print)
{
	int tmp;

	if ((stack == 'a' && s->size_a >= 2)
		|| (stack == 'b' && s->size_b >= 2))
	{
		if (stack == 'a')
		{
			tmp = pop(&(s->a), s->size_a);
			(s->a)[s->size_a - 1] = tmp;
		}
		else
		{
			tmp = pop(&(s->b), s->size_b);
			(s->b)[s->size_b - 1] = tmp;
		}
	}
	if (print)
		ft_printf("r%c\n", stack);
	if (s->flag_v)
	{
		if (print == 0)
			ft_printf("------\nr%c\n", stack);
		print_stack(s);
	}
}

static void	op_rev_helper(int **arr, int size)
{
	int tmp;
	int i;

	tmp = (*arr)[size - 1];
	i = size - 1;
	while (i > 0)
	{
		(*arr)[i] = (*arr)[i - 1];
		i--;
	}
	(*arr)[0] = tmp;
}

void		op_reverse(t_stack *s, char stack, bool print)
{
	if ((stack == 'a' && s->size_a >= 2)
		|| (stack == 'b' && s->size_b >= 2))
	{
		if (stack == 'a')
			op_rev_helper(&(s->a), s->size_a);
		else
			op_rev_helper(&(s->b), s->size_b);
	}
	if (print)
		ft_printf("rr%c\n", stack);
	if (s->flag_v)
	{
		if (print == 0)
			ft_printf("------\nrr%c\n", stack);
		print_stack(s);
	}
}
