/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:40:52 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/04 12:40:42 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_a(t_stack **stack, t_print_list **print_list)
{
	int				temp;
	t_stack			*list;
	t_print_list	*elem;

	list = *stack;
	if (list || list->next == NULL)
	{
		elem = ft_newlist_print("sa");
		temp = list->content;
		list->content = list->next->content;
		list->next->content = temp;
		ft_addback_print_lst(print_list, elem);
	}
}

void	swap_b(t_stack **stack, t_print_list **print_list)
{
	int				temp;
	t_stack			*list;
	t_print_list	*elem;

	list = *stack;
	if (list || list->next == NULL)
	{
		elem = ft_newlist_print("sb");
		temp = list->content;
		list->content = list->next->content;
		list->next->content = temp;
		ft_addback_print_lst(print_list, elem);
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b, t_print_list **print_list)
{
	t_stack			*temp;
	t_print_list	*elem;

	if (*stack_b)
	{
		elem = ft_newlist_print("pa");
		temp = (*stack_b)->next;
		ft_addfront_lst(stack_a, *stack_b);
		*stack_b = temp;
		ft_get_size(stack_a);
		ft_get_size(stack_b);
		ft_addback_print_lst(print_list, elem);
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b, t_print_list **print_list)
{
	t_stack			*temp;
	t_print_list	*elem;

	if (*stack_a)
	{
		elem = ft_newlist_print("pb");
		temp = (*stack_a)->next;
		ft_addfront_lst(stack_b, *stack_a);
		*stack_a = temp;
		ft_get_size(stack_a);
		ft_get_size(stack_b);
		ft_addback_print_lst(print_list, elem);
	}
}
