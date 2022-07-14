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
	int		i;
	t_list	*one;

	i = 1;
	one = ft_lstnew(argv[i]);
	ft_lstadd_back(&stack, one);
	i = 1;
	while (++i < argc)
		ft_lstadd_back(&stack, ft_lstnew(argv[i]));
	return (stack);
}
