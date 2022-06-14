/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:57:20 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:57:23 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Desplaza hacia arriba todos los elementos del stack a
 * una posición de forma que el primer elemento se convierte
 * en el último. Es la regla ra o rb.
 * PARAMETERS:
 * @param	t_list	**stack	Lista con números.
 * @param	char	*rule	Nombre de la regla a imprimir.
 */
void	rotate(t_list **stack, char *rule)
{
	t_list	*new_last;

	new_last = ft_lstnew((*stack)->content);
	pop_front(stack);
	ft_lstadd_back(stack, new_last);
	ft_putendl_fd(rule, 1);
	return ;
}

/**
 * DESCRIPTION:
 * Aplica la función rotate a los stacks a y b. Es la
 * regla rr.
 * PARAMETERS:
 * @param	t_list	**a	Stack 'a'.
 * @param	t_list	**b Stack 'b'.
 */
void	rotate_all(t_list **a, t_list **b)
{
	rotate(a, "");
	rotate(b, "");
	ft_putendl_fd("rr", 1);
	return ;
}
