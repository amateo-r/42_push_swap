/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psutils_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 10:53:40 by amateo-r          #+#    #+#             */
/*   Updated: 2022/06/02 10:53:44 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libps.h"

/**
 * DESCRIPTION:
 * Devuelve la cantidad de números que son menores a 'n'
 * en 'arr'.
 * PARAMETERS:
 * @param	int	*arr	Array de números donde se buscan los pequeños.
 * @param	int len		Longitud máxima donde buscar en 'arr'.
 * @param	int	n		Número pivote del que se buscan los pequeños a él.
 */
int	less_than(int *arr, int len, int n)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < len)
		if (n > arr[i])
			count++;
	return (count);
}

/**
 * DESCRIPTION:
 * Devuelve la cantidad de números que son mayores a 'n'
 * en 'arr'.
 * PARAMETERS:
 * @param	int	*arr	Array de números donde se buscan los mayores.
 * @param	int len		Longitud máxima donde buscar en 'arr'.
 * @param	int	n		Número pivote del que se buscan los mayores a él.
 */
int	greater_than(int *arr, int len, int n)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < len)
		if (n < arr[i])
			count++;
	return (count);
}

/**
 * DESCRIPTION:
 * Return the half of a longitude. If the number
 * is odd returns the half plus one if flag isnot
 * activated.
 * PARAMETERS:
 * @param	int	len	Number to reduce into half.
 * @param	int	flag	Boolean to determinate if
 * 						the return is plus one or
 * 						not.
 */
int	ft_halfsize(int len, int flag)
{
	int	half;

	half = 0;
	if (len % 2 != 0 && !flag)
		half = len / 2 + 1;
	else if (flag || len % 2 == 0)
		half = len / 2;
	return (half);
}

/**
 * DESCRIPTION:
 * Está función fue creada para encontra el punto medio de
 * una longitud. Si es impar redondea hacia arriba.
 * PARAMETERS:
 * @param	int	len	Longitud a buscar su punto medio.	
 */
int	find_middle(int len)
{
	if (len % 2 != 0)
		return ((len / 2) + 1);
	else
		return ((len / 2));
}

/**
 * DESCRIPTION:
 * Transforma una lista t_list en un array de enteros. Aloca memoria.
 * Retorna un array de enteros. Variable int *arr.
 * PARAMETERS:
 * @param	t_list	**lst	Array con números.
 * @param	int		size	Número más bajo en el array.
 */
int	*ft_lsttoarr(t_list **lst, int size)
{
	int		*arr;
	int		i;
	t_list	*lst_tmp;

	arr = (int *)malloc(sizeof(int) * size);
	lst_tmp = *lst;
	i = -1;
	while (++i < size)
	{
		arr[i] = ft_atoi((char *)lst_tmp->content);
		lst_tmp = lst_tmp->next;
	}
	return (arr);
}

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
