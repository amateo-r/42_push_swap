/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:56:48 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:56:50 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

void	sorting(t_list **a, t_list **b, int part_len);
void	recover(t_list **lst, int len, char *rule);
void	qs_three(t_list **a, t_list **b);
void	qs_repeat(t_list **a, t_list **b, int part_len);
void	quicksort(t_list **a, t_list **b, int des);

/**
 * DESCRIPTION:
 * No fucking idea.
 * PARAMETERS:
 * @param	t_list	**a			Final list.
 * @param	t_ist	**b			Temporal list.
 * @param	int		part_len	Length of partition to sort.
 */
void	sorting(t_list **a, t_list **b, int part_len)
{
	if (part_len == 1)
	{
		push(b, a, PA);
		if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
			swap(a, SA);
	}
	else if (part_len == 2)
	{
		if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
			swap(a, SA);
		if (ft_atoi((*b)->content) < ft_atoi((*b)->next->content))
			swap(b, SB);
		push(b, a, PA);
		push(b, a, PA);
	}
	else if (part_len == 3)
		qs_three(a, b);
	else if (part_len > 3)
		qs_repeat(a, b, part_len);
	return ;
}

/**
 * DESCRIPTION:
 * Mueve al principio los elementos de 'lst' 'len' veces.
 * Move to beguining the elements of lst len times.
 * PARAMETERS:
 * @param	t_list	**lst	Lista de números a modificar.
 * @param	int		len		Cantidad de números que mover al 
							principio.
 * @param	char	*rule	Nombre de la regla empleada.
 */
void	recover(t_list **lst, int len, char *rule)
{
	while (len > 0)
	{
		reverse(lst, rule);
		len--;
	}
	return ;
}

/**
 * DESCRIPTION:
 * Ordena un conjunto de tres números durante una partición.
 * Sorts a set of three numbers during a parition.
 * PARAMETERS:
 * @param	t_list	**a	Lista de números final.
 * @param	t_list	**b	Lista de números donde está la partición.
 */
void	qs_three(t_list **a, t_list **b)
{
	int	*arr;
	int	max;
	int	rec;
	int	i;

	arr = ft_lsttoarr(b, 3);
	max = quickselect(arr, 0, 2, 3);
	rec = 0;
	i = 2;
	while (ft_atoi((char *)(*b)->content) != max && i > 0)
	{
		rotate(b, RB);
		rec++;
		i--;
	}
	push(b, a, PA);
	recover(b, rec, RRB);
	if (ft_atoi((char *)(*b)->content) < ft_atoi((char *)(*b)->next->content))
		swap(b, SB);
	push(b, a, PA);
	push(b, a, PA);
	return ;
}

/**
 * DESCRIPTION:
 * Inverted Quicksort process. Works like quicksort, but it does 
 * during the back of the recursivity. It must be executed only when
 * one partition has more than three numbers.
 * PARAMETERS:
 * @param	t_list	**a			Lista de números final.
 * @param	t_list	**b			Lista de números parcial.
 * @param	int		part_len	Cantidad de números de una partición.
 */
void	qs_repeat(t_list **a, t_list **b, int part_len)
{
	int	rec;
	int	middle;
	int	greaters;
	int	*arr;

	arr = ft_lsttoarr(b, part_len);
	middle = quickselect(arr, 0, part_len - 1, find_middle(part_len));
	greaters = greater_than(arr, part_len, middle);
	rec = despartition(a, b, part_len, arr);
	part_len = find_middle(part_len);
	recover(b, rec, RRB);
	if (part_len >= 2)
		quicksort(a, b, greaters);
	sorting(a, b, part_len);
	return ;
}

/**
 * DESCRIPTION:
 * Sorting algorithim of numbers. Sorts the numbers of one list constantly 
 * spliting the list until its minimun division. Given the ruels it must be 
 * do it through rules and two lists.
 * PARAMETERS:
 * @param	t_list	**a	Lista que debe estar ordenada.
 * @param	t_list	**b	Lista que se puede emplear para ordenar.
 * @param	int		des	Bandera que sirve para la vuelta de la recursividad.
 */
void	quicksort(t_list **a, t_list **b, int des)
{
	int	part_len;
	int	rec;

	rec = 0;
	if (!des)
		part_len = partition(a, b, ft_lstsize(*a));
	else
	{
		part_len = partition_rec(a, b, des);
		rec = des - part_len;
		if (des - part_len == 0)
			rec = des;
		if (rec > 2)
			quicksort(a, b, rec);
	}
	if (ft_lstsize(*a) > 1 && !des)
		quicksort(a, b, des);
	sorting(a, b, part_len);
	return ;
}
