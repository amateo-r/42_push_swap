/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickselect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:55:34 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:55:42 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * It goes spliting the list into halfs from a pivot.
 * RETURN:
 * Return index of half value.
 * PARAMETERS:
 * @param	int	*arr	Array con números.
 * @param	int	low		Índice más bajo en el array.
 * @param	int	high	Índice más alto en el array.
 */
int	qs_partition(int *arr, int low, int high)
{
	int	pivot;
	int	pivot_loc;
	int	i;
	int	tmp;

	pivot = arr[high];
	pivot_loc = low;
	i = low;
	while (i <= high)
	{
		if (arr[i] < pivot)
		{
			tmp = arr[i];
			arr[i] = arr[pivot_loc];
			arr[pivot_loc] = tmp;
			pivot_loc++;
		}
		i++;
	}
	tmp = arr[high];
	arr[high] = arr[pivot_loc];
	arr[pivot_loc] = tmp;
	return (pivot_loc);
}

/**
 * DESCRIPTION:
 * Encuentra el número medio de un conjunto de valores.
 * Se espera que low y high estén dentro de arr.
 * Find the half number from a set of values. It is
 * expected that low and high are in arr.
 * RETURN:
 * Return half value of list arr.
 * PARAMETERS:
 * @param	int	*arr	Array de números.
 * @param	int	low		Índice más bajo usado para buscar el punto medio.
 * @param	int	high	Índice más alto usado para buscar el punto medio.
 * @param	int	k		Longitud donde buscar.
 */
int	quickselect(int *arr, int low, int high, int k)
{
	int	partition;

	if (high == 1)
	{
		if (arr[0] > arr[1])
			return (arr[0]);
		else
			return (arr[1]);
	}
	partition = qs_partition(arr, low, high);
	if (partition == k - 1)
		return (arr[partition]);
	else if (partition < k - 1)
		return (quickselect(arr, partition + 1, high, k));
	else
		return (quickselect(arr, low, partition - 1, k));
}
