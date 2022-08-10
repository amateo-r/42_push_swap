/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:14:22 by amateo-r          #+#    #+#             */
/*   Updated: 2022/05/12 15:50:51 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

t_list	*add_elements(char **matrix, t_list *stack)
{
	int	i;
	t_list	*one;

	one = ft_lstnew(matrix[0]);
	ft_lstadd_back(&stack, one);
	i = 0;
	while (matrix[++i] != 0)
		ft_lstadd_back(&stack, ft_lstnew(matrix[i]));
	return (stack);
}

/**
 * DESCRIPTION:
 * Allocates memory and create lists.
 * RETURN:
 * Return the allocated stack.
 * PARAMETERS:
 * @param	int		argc	Number of input parameters.
 * @param	char	**argv	Input paramenters.
 * @param	t_list	*stack	List where argv data will stored.
 */
t_list	*init_stack(int argc, char **argv, t_list *stack)
{
	char	**matrix;

	if (argc == 2)
	{
		matrix = ft_split(argv[1], ' ');
		stack = add_elements(matrix, stack);
	}
	else
		stack = add_elements(&argv[1], stack);
	return (stack);
}
