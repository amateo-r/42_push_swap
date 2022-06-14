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
 * Es un proceso especial parecido a la función 'partition'.
 * Funciona igual que 'partition'. En este caso de hace una partición
 * de una partición. Se envían los números más grandes del pivote de
 * la partición a la lista 'a'.
 * RETURN:
 * Cantidad de números movidos a 'a'.
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
 * Funciona igual que la función 'partition'. Coloca todos los
 * números que no ha enviado a 'dst' y que haya movido durante su
 * búsqueda al principio de nuevo..
 * RETURN:
 * Devuelve la longitud de la partición enviada a 'dst'.
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
	count = less_than(arr, len, middle);
	rec = 0;
	part_len = count;
	while (count > 0)
	{
		if (ft_atoi((char *)(*src)->content) < middle)
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
 * Coge lista 'src' y la parte en dos. Los números más pequeños a
 * el número medio de 'src' son volcados en 'dst'.
 * RETURN:
 * Cantidad de números movidos a 'dst'.
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
