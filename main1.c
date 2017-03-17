/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:12:31 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:28:52 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//main for checker

static void	apply_instr_helper(t_stack *s, char *str)
{
	if (ft_strcmp(str, "rra") == 0)
		op_reverse(s, 'a', 0);
	else if (ft_strcmp(str, "rrb") == 0)
		op_reverse(s, 'b', 0);
	else if (ft_strcmp(str, "rrr") == 0)
		op_reverse_ab(s, 0);
}

static void	apply_instr(t_stack *s, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		op_swap(s, 'a', 0);
	else if (ft_strcmp(str, "sb") == 0)
		op_swap(s, 'b', 0);
	else if (ft_strcmp(str, "ss") == 0)
		op_swap_ab(s, 0);
	else if (ft_strcmp(str, "pa") == 0)
		op_push(s, 'a', 0);
	else if (ft_strcmp(str, "pb") == 0)
		op_push(s, 'b', 0);
	else if (ft_strcmp(str, "ra") == 0)
		op_rotate(s, 'a', 0);
	else if (ft_strcmp(str, "rb") == 0)
		op_rotate(s, 'b', 0);
	else if (ft_strcmp(str, "rr") == 0)
		op_rotate_ab(s, 0);
	else
		apply_instr_helper(s, str);
}

int			main(int ac, char **av)
{
	t_stack		*s;
	char		*r_std;

	if (ac == 1)
		return (0);
	if (!(s = create_stack(ac, av)))
		return (error());
	r_std = 0;
	while (get_next_line(0, &r_std) > 0)
	{
		if (!valid_instr(r_std))
		{
			ft_strdel(&r_std);
			free_stack(s);
			return (error());
		}
		apply_instr(s, r_std);
		ft_strdel(&r_std);
	}
	if (is_sort(s->a, s->size_a) && s->size_b == 0)
		return (res_ok(s));
	else
		return (res_ko(s));
}
