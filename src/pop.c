/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:48:45 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:48:48 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Elimina el último elemento de una lista.
 * PARAMETERS:
 * @param	t_list	**stack	Lista con elementos.
 */
void	pop_back(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	if (!head)
		return ;
	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	free(last);
	return ;
}

/**
 * DESCRIPTION:
 * Elimina el primer elemento de una lista.
 * PARAMETERS:
 * @param	t_list	**stack	Lista con elementos.
 */
void	pop_front(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	return ;
}
