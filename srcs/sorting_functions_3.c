/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:07:19 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/01 09:30:19 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ss(t_stack **stack_a, t_stack **stack_b, t_print_list **print_list)
{
	t_print_list	*elem;

	elem = ft_newlist_print("ss");
	swap_a(stack_a, print_list);
	swap_b(stack_b, print_list);
	ft_addback_print_lst(print_list, elem);
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_print_list **print_list)
{
	t_print_list	*elem;

	elem = ft_newlist_print("rr");
	rotate_a(stack_a, print_list);
	rotate_b(stack_b, print_list);
	ft_addback_print_lst(print_list, elem);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_print_list **print_list)
{
	t_print_list	*elem;

	elem = ft_newlist_print("rrr");
	reverse_rotate_a(stack_a, print_list);
	reverse_rotate_b(stack_b, print_list);
	ft_addback_print_lst(print_list, elem);
}
