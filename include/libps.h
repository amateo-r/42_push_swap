/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:00:35 by amateo-r          #+#    #+#             */
/*   Updated: 2022/05/12 14:29:52 by amateo-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "./libft/libft.h"

# define PA "pa"
# define PB "pb"
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

//	psutils_00.C
int		less_than(int *arr, int len, int n);
int		greater_than(int *arr, int len, int n);
int		ft_halfsize(int len, int flag);
int		find_middle(int len);
int		*ft_lsttoarr(t_list **lst, int size);

//	exceptions_handlers.c
// int		chk_numbers(char **argv);
// int		chk_duplicated(char **argv);
int		input_manager(int argc, char **argv, int k);

//	partition.c
int		despartition(t_list **a, t_list **b, int part_len, int *arr);
int		partition_rec(t_list **src, t_list **dst, int len);
int		partition(t_list **src, t_list **dst, int len);

//	quicksort.c
void	recover(t_list **lst, int len, char *rule);
void	quicksort(t_list **a, t_list **b, int des);

//	smallsort.c
void	sortthree(t_list **a);
void	sortfive(t_list **a, t_list **b);

//	pop.c
void	pop_front(t_list **stack);
void	pop_back(t_list **stack);

//	rules (push.c, reverse.c, rotate.c, swap.c)
void	push(t_list **src, t_list **dst, char *rule);
void	reverse(t_list **stack, char *rule);
void	reverse_all(t_list **a, t_list **b);
void	rotate(t_list **stack, char *rule);
void	rotate_all(t_list **a, t_list **b);
void	swap(t_list **stack, char *rule);
void	swap_all(t_list **a, t_list **b);

//	others
int		quickselect(int *arr, int low, int high, int k);
t_list	*init_stack(int argc, char **argv, t_list *stack);
t_list	*init_push(t_list **src, t_list *dst);

//	things not relevant (trash.c)
void	issorted(t_list **a);
void	ft_lstprint(t_list **head);
void	ft_lstnprint(t_list **head, int len);

#endif
