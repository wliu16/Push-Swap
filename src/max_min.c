/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:19:18 by wliu              #+#    #+#             */
/*   Updated: 2017/02/11 10:19:18 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	calc_max_min(t_stack *s)
{
	s->a_min = arr_min(s->a, s->size_a);
	s->a_max = arr_max(s->a, s->size_a);
	s->a_min_ind = arr_min_index(s->a, s->size_a);
	s->a_max_ind = arr_max_index(s->a, s->size_a);
	s->b_min = arr_min(s->b, s->size_b);
	s->b_max = arr_max(s->b, s->size_b);
	s->b_min_ind = arr_min_index(s->b, s->size_b);
	s->b_max_ind = arr_max_index(s->b, s->size_b);
}
