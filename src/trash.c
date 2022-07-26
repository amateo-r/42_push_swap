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
			flag = 0;
		*head = (*head)->next;
	}
	*head = tmp;
	// if (flag)
	// 	printf("\n\nDesorden encontrado tonto.\n");
	// else
	// 	printf("\n\nOrdenao to wapo, campeón.\n");
	return ;
}
