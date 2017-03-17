/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:33:43 by wliu              #+#    #+#             */
/*   Updated: 2017/02/11 10:10:36 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		dup_num(int *arr, int data, int comp_size)
{
	int i;

	i = 0;
	while (i < comp_size)
	{
		if (data == arr[i])
			return (1);
		i++;
	}
	return (0);
}

static t_stack	*init_stack(int flag_v, int size)
{
	t_stack *s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->a = (int *)malloc(sizeof(int) * size);
	s->b = (int *)malloc(sizeof(int) * size);
	s->op_num_a = (int *)malloc(sizeof(int) * size);
	s->op_num_b = (int *)malloc(sizeof(int) * size);
	s->size_a = size;
	s->size_b = 0;
	s->flag_v = flag_v;
	return (s);
}

static t_stack	*create_stack_helper(int flag_v, char *str, int data)
{
	t_stack	*s;
	char	**split;
	int		i;

	split = ft_strsplit(str, ' ');
	i = 0;
	while (split[i])
		i++;
	s = init_stack(flag_v, i);
	i = 0;
	while (split[i])
	{
		if (!valid_num_input(split[i], &data) || dup_num(s->a, data, i))
			return (free_stack(s));
		s->a[i] = data;
		i++;
	}
	free_matrix(split);
	return (s);
}

t_stack			*create_stack(int ac, char **av)
{
	t_stack	*s;
	int		i;
	int		data;
	int		flag_v;

	data = 0;
	i = 1;
	flag_v = 0;
	if (ft_strcmp(av[i], "-v") == 0 && i++)
		flag_v = 1;
	if (i == ac - 1 && ft_strchr(av[i], ' '))
		return (create_stack_helper(flag_v, av[ac - 1], data));
	s = init_stack(flag_v, ac - 1 - flag_v);
	while (av[i])
	{
		if (!valid_num_input(av[i], &data)
				|| dup_num(s->a, data, i - 1 - flag_v))
			return (free_stack(s));
		s->a[i - 1 - flag_v] = data;
		i++;
	}
	return (s);
}
