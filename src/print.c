/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:29:39 by wliu              #+#    #+#             */
/*   Updated: 2017/02/11 10:18:56 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	print_list(int *arr, int size)
{
	int i;

	if (size == 0)
	{
		ft_printf("empty\n");
		return ;
	}
	i = 0;
	while (i < size)
	{
		ft_printf("%d, ", arr[i]);
		i++;
	}
	ft_putchar('\n');
}

void		print_stack(t_stack *s)
{
	if (!s)
		return ;
	ft_printf("stack a (%d elements): ", s->size_a);
	print_list(s->a, s->size_a);
	ft_printf("stack b (%d elements): ", s->size_b);
	print_list(s->b, s->size_b);
}
