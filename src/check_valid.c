/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:37:00 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:00:11 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			valid_instr(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
			|| ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0
			|| ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0
			|| ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0
			|| ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0
			|| ft_strcmp(str, "rrr") == 0)
		return (1);
	else
		return (0);
}

int			valid_num_input(const char *str, int *data)
{
	long	res;
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	res = 0;
	if (!(*str))
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if (sign * res > 2147483647 || sign * res < -2147483648)
			return (0);
		str++;
	}
	*data = res * sign;
	return (1);
}
