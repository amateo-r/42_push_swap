/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:57:59 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:58:01 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Intercambia los dos primeros elementos encima del stack. No hace nada si
 * hay uno o menos elementos. Es la regla sa o sb.
 * PARAMETERS:
 * @param	t_list	*stack	Stack con números.
 * @param	char	*rule	Nombre de la regla a imprimir.
 */
void	swap(t_list **stack, char *rule)
{
	t_list	*new_first;
	t_list	*new_second;

	new_second = ft_lstnew((*stack)->content);
	pop_front(stack);
	new_first = ft_lstnew((*stack)->content);
	pop_front(stack);
	ft_lstadd_front(stack, new_second);
	ft_lstadd_front(stack, new_first);
	if (rule)
		ft_putendl_fd(rule, 1);
	return ;
}

/**
 * DESCRIPTION:
 * Aplica la función swap a los stacks a y b. Es la regla ss
 * PARAMETERS:
 * @param	t_list	**a	Stack 'a'.
 * @param	t_list	**b	Stack 'b'.
 */
void	swap_all(t_list **a, t_list **b)
{
	swap(a, "");
	swap(b, "");
	ft_putendl_fd("ss", 1);
	return ;
}
