/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:27:49 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 12:27:51 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Special process like function 'partition'. In this case makes a 
 * partition of a partition. Numbers bigger than the pivot of the 
 * parition are sent to list a.
 * RETURN:
 * Return the count of numbers pushed to list a.
 * PARAMETERS:
 * @param	t_list	**a			Lista donde se mete la partición.
 * @param	t_list	**b			Lista donde se hace la partición.
 * @param	int		part_len	Longitud de la partición inicial.
 * @param	int		*arr		Array de la partición a dividir.
 */
int	despartition(t_list **a, t_list **b, int part_len, int *arr)
{
	int	middle;
	int	greaters;
	int	recover;

	middle = quickselect(arr, 0, part_len - 1, find_middle(part_len));
	greaters = greater_than(arr, part_len, middle);
	recover = 0;
	while (greaters > 0)
	{
		if (ft_atoi((char *)(*b)->content) > middle)
		{
			push(b, a, PA);
			greaters--;
		}
		else
		{
			rotate(b, RB);
			recover++;
		}
	}
	return (recover);
}

/**
 * DESCRIPTION:
 * Works like function 'parition'. Place all numbers that hadn't
 * sent to dst and that were moved in the seek to the beguining.
 * RETURN:
 * The length of the partition sent to list dst.
 * PARAMETERS:
 * @param	t_list	**src	Lista donde se hace la partición.
 * @param	t_list	**dst	Lista donde se mete la partición.
 * @param	int		len		Longitud de 'src'.
 */
int	partition_rec(t_list **src, t_list **dst, int len)
{
	int	middle;
	int	*arr;
	int	part_len;
	int	count;
	int	rec;

	arr = ft_lsttoarr(src, len);
	middle = quickselect(arr, 0, len - 1, find_middle(len));
	count = less_than(arr, len, middle) + 1;
	rec = 0;
	part_len = count;
	while (count > 0)
	{
		if (ft_atoi((char *)(*src)->content) <= middle)
		{
			push(src, dst, PB);
			count--;
		}
		else
		{
			rotate(src, RA);
			rec++;
		}
	}
	recover(src, rec, RRA);
	return (part_len);
}

/**
 * DESCRIPTION:
 * Coge la lista 'src' y la parte en dos. Los números más pequeños a
 * el número medio de 'src' son volcados en 'dst'.
 * Splits list 'src' in two. Numbers lesser than half value of src
 * are overthrow to dst.
 * RETURN:
 * Count of numbers pushed to list dst.
 * PARAMETERS:
 * @param	t_list	**src	Lista donde se hace la partición.
 * @param	t_list	**dst	Lista donde se mete la partición.
 * @param	int		len		Longitud de 'src'.
 */
int	partition(t_list **src, t_list **dst, int len)
{
	int	middle;
	int	*arr;
	int	part_len;
	int	count;

	arr = ft_lsttoarr(src, len);
	middle = quickselect(arr, 0, len - 1, find_middle(len));
	count = less_than(arr, len, middle);
	part_len = count;
	while (count > 0)
	{
		if (ft_atoi((char *)(*src)->content) < middle)
		{
			push(src, dst, PB);
			count--;
		}
		else
			rotate(src, RA);
	}
	free(arr);
	return (part_len);
}
