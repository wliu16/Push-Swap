/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_max_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:06:34 by wliu              #+#    #+#             */
/*   Updated: 2017/02/11 10:06:35 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arr_min_index(int *arr, int size)
{
	int min;
	int min_index;
	int i;

	if (!arr || size == 0)
		return (-1);
	min = arr[0];
	min_index = 0;
	i = 1;
	while (i < size)
	{
		if (arr[i] <= min)
		{
			min = arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	arr_max_index(int *arr, int size)
{
	int max;
	int max_index;
	int i;

	if (!arr || size == 0)
		return (-1);
	max = arr[0];
	max_index = 0;
	i = 1;
	while (i < size)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int	arr_max(int *arr, int size)
{
	int max;
	int i;

	if (!arr || size == 0)
		return (-1);
	max = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] >= max)
			max = arr[i];
		i++;
	}
	return (max);
}

int	arr_min(int *arr, int size)
{
	int min;
	int i;

	if (!arr || size == 0)
		return (-1);
	min = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] <= min)
			min = arr[i];
		i++;
	}
	return (min);
}
