/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:37:58 by amateo-r          #+#    #+#             */
/*   Updated: 2022/07/25 12:38:00 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Sort an input list of three numbers into
 * stack a.
 * PARAMETERS:
 * @param	t_list	**a	Final sorted stack.
 */
void	sortthree(t_list **a)
{
	if (ft_atoi((*a)->content) > ft_atoi(ft_lstlast(*a)->content))
	{
		if (ft_atoi((*a)->content) < ft_atoi((*a)->next->content))
			reverse(a, RRA);
		else
		{
			rotate(a, RA);
			swap(a, SA);
		}
	}
	if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
		swap(a, SA);
	if (ft_atoi((*a)->next->content) > ft_atoi(ft_lstlast(*a)->content))
	{
		swap(a, SA);
		rotate(a, RA);
	}
	return ;
}

/**
 * DESCRIPTION:
 * Sorts an input list of five numbers into 
 * stack a.
 * PARAMETERS:
 * @param	t_list	**a	Final sorted stack.
 * @param	t_list	**b	Stack to extra operations.
 */
 void	sortfive(t_list **a, t_list **b)
 {
	 1 2 3 4 5 ¿Bubble?

	 3 5 4 2 1
	 return ;
 }
