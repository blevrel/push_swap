/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 08:49:04 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/05 18:03:41 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_get_size(t_stack **stack)
{
	t_stack	*list;

	if (*stack)
	{
		list = *stack;
		while (list)
		{
			list->size = ft_sizelst(*stack);
			list = list->next;
		}
	}
}

void	init_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = NULL;
	ft_get_size(stack_a);
	ft_get_size(stack_b);
}

void	sort_small_list(t_stack **stack_a)
{
	t_stack			*stack_b;
	int				orig_size;
	t_print_list	*print_list;
	t_print_list	*elem;

	stack_b = NULL;
	orig_size = (*stack_a)->size;
	print_list = ft_newlist_print(NULL);
	while (is_sorted(stack_a) != 1)
	{
		bring_min_up(stack_a, &print_list);
		if (stack_b == NULL)
		{
			init_stack_b(stack_a, &stack_b);
			elem = ft_newlist_print("pb");
			ft_addback_print_lst(&print_list, elem);
			continue ;
		}
		push_b(stack_a, &stack_b, &print_list);
	}
	while ((*stack_a)->size != orig_size)
		push_a(stack_a, &stack_b, &print_list);
	display_print_list(&print_list);
	free_linked_list(&stack_b);
}

void	sort_big_list(t_stack **stack_a)
{
	t_print_list	*print_list;
	int				shift;

	print_list = ft_newlist_print(NULL);
	shift = 0;
	while (is_sorted(stack_a) != 1)
	{
		compare_bytes(stack_a, &print_list, shift);
		shift++;
	}
	display_print_list(&print_list);
}

void	bring_min_up(t_stack **stack, t_print_list **print_list)
{
	int		min;
	t_stack	*list;
	int		i;
	int		index;

	i = 0;
	min = 2147483647;
	list = *stack;
	index = 0;
	while (list)
	{
		if (list->content < min)
		{
			min = list->content;
			index = i;
		}
		i++;
		list = list->next;
	}
	if (index <= (*stack)->size / 2)
		while ((*stack)->content != min)
			rotate_a(stack, print_list);
	else
		while ((*stack)->content != min)
			reverse_rotate_a(stack, print_list);
}
