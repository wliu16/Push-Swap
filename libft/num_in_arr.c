/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_in_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:05:37 by wliu              #+#    #+#             */
/*   Updated: 2017/02/11 10:05:44 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	num_in_arr(int n, int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (n == array[i])
			return (1);
		i++;
	}
	return (0);
}
