/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:56:24 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/06 15:32:35 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(t_stack **stack, t_print_list **print_list)
{
	t_stack			*list;
	t_print_list	*elem;

	if (*stack)
	{
		elem = ft_newlist_print("ra");
		list = *stack;
		*stack = (*stack)->next;
		list->next = NULL;
		ft_addback_lst(stack, list);
		ft_addback_print_lst(print_list, elem);
	}
}

void	rotate_b(t_stack **stack, t_print_list **print_list)
{
	t_stack			*list;
	t_print_list	*elem;

	if (*stack)
	{
		elem = ft_newlist_print("rb");
		list = *stack;
		*stack = (*stack)->next;
		list->next = NULL;
		ft_addback_lst(stack, list);
		ft_addback_print_lst(print_list, elem);
	}
}

void	reverse_rotate_a(t_stack **stack, t_print_list **print_list)
{
	t_stack			*list;
	t_print_list	*elem;

	if (*stack)
	{
		list = *stack;
		elem = ft_newlist_print("rra");
		ft_addback_print_lst(print_list, elem);
		while (list->next)
		{
			if (list->next->next == NULL)
			{
				ft_addfront_lst(stack, list->next);
				list->next = NULL;
				break ;
			}
			list = list->next;
		}
	}
}

void	reverse_rotate_b(t_stack **stack, t_print_list **print_list)
{
	t_stack			*list;
	t_print_list	*elem;

	if (*stack)
	{
		list = *stack;
		elem = ft_newlist_print("rrb");
		ft_addback_print_lst(print_list, elem);
		while (list->next)
		{
			if (list->next->next == NULL)
			{
				ft_addfront_lst(stack, list->next);
				list->next = NULL;
				ft_printf("rrb\n");
				break ;
			}
			list = list->next;
		}
	}
}
