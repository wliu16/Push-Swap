/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:20:11 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:31:21 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//ss, rr, rrr
//pop and push for pa/pb

void	op_swap_ab(t_stack *s, bool print)
{
	bool flag_v;

	flag_v = s->flag_v;
	s->flag_v = 0;
	op_swap(s, 'a', 0);
	op_swap(s, 'b', 0);
	if (print)
		ft_printf("ss\n");
	s->flag_v = flag_v;
	if (s->flag_v)
	{
		if (print == 0)
			ft_printf("------\nss\n");
		print_stack(s);
	}
}

void	op_rotate_ab(t_stack *s, bool print)
{
	bool flag_v;

	flag_v = s->flag_v;
	s->flag_v = 0;
	op_rotate(s, 'a', 0);
	op_rotate(s, 'b', 0);
	if (print)
		ft_printf("rr\n");
	s->flag_v = flag_v;
	if (s->flag_v)
	{
		if (print == 0)
			ft_printf("------\nrr\n");
		print_stack(s);
	}
}

void	op_reverse_ab(t_stack *s, bool print)
{
	bool flag_v;

	flag_v = s->flag_v;
	s->flag_v = 0;
	op_reverse(s, 'a', 0);
	op_reverse(s, 'b', 0);
	if (print)
		ft_printf("rrr\n");
	s->flag_v = flag_v;
	if (s->flag_v)
	{
		if (print == 0)
			ft_printf("------\nrrr\n");
		print_stack(s);
	}
}

int		pop(int **arr, int size)
{
	int res;
	int i;

	if (size == 0)
		return (-1);
	res = (*arr)[0];
	i = 0;
	while (i < size - 1)
	{
		(*arr)[i] = (*arr)[i + 1];
		i++;
	}
	return (res);
}

void	push(int **arr, int elem, int size)
{
	int	i;

	i = size;
	while (i > 0)
	{
		(*arr)[i] = (*arr)[i - 1];
		i--;
	}
	(*arr)[0] = elem;
}
