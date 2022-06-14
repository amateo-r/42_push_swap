/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:55:14 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:55:16 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Toma el primer elmento del stack src y lo pone encima
 * del stack dst. No hace nada si src está vacío. Es la
 * regla pa o pb.
 * PARAMATERS:
 * @param	t_list	*src	Lista donde está el primer elemento a remover.
 * @param	t_list	*dst	Lista donde se añadirá el primer elmento de src.
 */
void	push(t_list **src, t_list **dst, char *rule)
{
	t_list	*fst_element;

	fst_element = NULL;
	if (!*src || !(*src)->content)
		return ;
	if ((*dst)->content == NULL)
		(*dst)->content = (*src)->content;
	else
	{
		fst_element = ft_lstnew((*src)->content);
		ft_lstadd_front(dst, fst_element);
	}
	pop_front(src);
	ft_putendl_fd(rule, 1);
	return ;
}

/**
 * DESCRIPTION:
 * Funciona de la misma forma que push. Si no hay elementos guardados
 * en dst crea una nueva lista.
 * PARAMETERS:
 * @param	t_list	*src	Lista donde está el primer elemento a remover.
 * @param	t_list	*dst	Lista donde se añadirá el primer elemento de src.
 */
t_list	*init_push(t_list **src, t_list *dst)
{
	t_list	*fst_element;

	fst_element = NULL;
	if (!src)
		return (NULL);
	dst = ft_lstnew((*src)->content);
	pop_front(&src[0]);
	return (dst);
}
