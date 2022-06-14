/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:57:02 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:57:08 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
* DESCRIPTION:
* Desplaza hacia abajo todos los elementos del stack a una
* posición, de forma que el último elemento se convierte en
* el primero. Es la regla rra o rrb.
* PARAMETERS:
* @param	t_list	**stack	Lista con los números.
* @param	char	*rule	Nombre de la regla a imprimir.
*/
void	reverse(t_list **stack, char *rule)
{
	t_list	*new_first;

	new_first = ft_lstnew((ft_lstlast(*stack))->content);
	pop_back(stack);
	ft_lstadd_front(stack, new_first);
	if (rule)
		ft_putendl_fd(rule, 1);
	return ;
}

/**
 * DESCRIPTION:
 * Aplica la función reverse a dos stacks. Es la regla rrr.
 * PARAMETER:
 * @param	t_list	**a	Stack 'a'.
 * @param	t_list	**b	Stack 'b'.
 */
void	reverse_all(t_list **a, t_list **b)
{
	reverse(a, "");
	reverse(b, "");
	ft_putendl_fd("rrr", 1);
	return ;
}
