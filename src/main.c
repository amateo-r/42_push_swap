/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:02:40 by amateo-r          #+#    #+#             */
/*   Updated: 2022/05/27 18:50:30 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		len;
	// int		*arr;

	a = NULL;
	b = NULL;
	if (input_manager(argc, argv) != 0)
	{
		a = init_stack(argc, argv, a);
		b = ft_lstnew(0);
		len = ft_lstsize(a);
		if (len <= 3)
			sortthree(&a);
		else
			quicksort(&a, &b, 0);
		// ft_lstprint(&a);
		issorted(&a);
	}
	else
		printf("Algo mal\n");
	return (0);
}
