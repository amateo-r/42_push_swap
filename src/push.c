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
 * Takes first element of the stack src and put it up of the
 * stack dst. It doesn't nothing if src is empety. Rule pa or pb.
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
