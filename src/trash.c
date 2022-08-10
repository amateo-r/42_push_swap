/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:58:15 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:58:19 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Print list.
 * PARAMETERS:
 * @param	t_list	**head	List to print.
 */
void	ft_lstprint(t_list **head)
{
	int		i;
	t_list	*tmp;

	tmp = *head;
	ft_putstr_fd("===========\n", 1);
	ft_putstr_fd("Imprimiendo lista...\n", 1);
	i = 0;
	while ((*head))
	{
		printf("[%d]: %s\n", i, (char *)(*head)->content);
		*head = (*head)->next;
		i++;
	}
	ft_putstr_fd("===========\n", 1);
	*head = tmp;
}

void	issorted(t_list **head)
{
	int		len;
	int		flag;
	t_list	*tmp;

	len = ft_lstsize(*head);
	flag = 0;
	tmp = *head;
	while (--len && !flag)
	{
		if (ft_atoi((*head)->content) > ft_atoi((*head)->next->content))
			flag = 1;
		*head = (*head)->next;
	}
	*head = tmp;
	if (flag)
		printf("\n\nDesorden encontrado tonto.\n");
	else
		printf("\n\nOrdenao to wapo, campeón.\n");
	return ;
}
