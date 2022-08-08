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
 * Checks the less number of instructions needed to
 * push numbers of stack b into stack a.
 * RETURN:
 * If the right path is lesser than left returns 1 
 * else return 0. If the number to sort is the middle
 * return 2 because is a special case.
 * PARAMETERS:
 * @param	t_list	**a		Final sorted stack.
 * @param	t_list	**b		Stack to extra operations.
 * @param	int		middle	Half number of the stack a.
 */
int	check_shortpath(t_list **a, t_list **b, int middle)
{
	int		path;
	t_list	*tmp;

	tmp = *a;
	path = 0;
	while ((*a) && ft_atoi((*b)->content) > ft_atoi((*a)->content))
	{
		path++;
		*a = (*a)->next;
	}
	*a = tmp;
	if (path >= 2)
	{
		if (ft_lstsize(*a) - path == 2 || \
			middle == ft_atoi(ft_lstlast(*b)->content))
			return (2);
		return (0);
	}
	else
		return (1);
}

/**
 * DESCRIPTION:
 * Take the two numbers in stack b and push them into
 * stack a. They are sorted in the process.
 * PARAMETERS:
 * @param	t_list	**a		Final sorted stack.
 * @param	t_list	**b		Stactk to extra operations.
 * @param	int		middle	Middle value of all numbers.
 */
void	sortfive_push_two(t_list **a, t_list **b, int middle)
{
	int	path;

	while (*b)
	{
		path = check_shortpath(a, b, middle);
		if (path == 1)
		{
			while (ft_atoi((*b)->content) > ft_atoi((*a)->content))
				rotate(a, RA);
			push(b, a, PA);
			while (ft_atoi(ft_lstlast(*a)->content) < ft_atoi((*a)->content))
				reverse(a, RRA);
		}
		else if (path == 0 || path == 2)
		{
			while (ft_atoi((*b)->content) < ft_atoi(ft_lstlast(*a)->content))
				reverse(a, RRA);
			push(b, a, PA);
			if (path == 2)
				push(b, a, PA);
			while (ft_atoi((*a)->content) > ft_atoi(ft_lstlast(*a)->content))
				rotate(a, RA);
		}
	}
	return ;
}

/**
 * DESCRIPTION:
 * Sorts an input list of five numbers into 
 * stack a. Must be between 8-12 instructions.
 * PARAMETERS:
 * @param	t_list	**a	Final sorted stack.
 * @param	t_list	**b	Stack to extra operations.
 */
void	sortfive(t_list **a, t_list **b)
{
	int	middle;
	int	*arr;

	arr = ft_lsttoarr(a, 5);
	middle = quickselect(arr, 0, 5 - 1, find_middle(5));
	free(arr);
	push(a, b, PB);
	push(a, b, PB);
	sortthree(a);
	sortfive_push_two(a, b, middle);
	return ;
}
