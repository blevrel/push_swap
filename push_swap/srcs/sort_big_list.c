/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:56:43 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/05 18:50:56 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	compare_bytes(t_stack **stack_a, t_print_list **print_list, int shift)
{
	int		bit;
	int		i;
	int		orig_size;
	t_stack	*stack_b;

	stack_b = NULL;
	i = -1;
	orig_size = (*stack_a)->size;
	while (++i < orig_size)
	{
		bit = ((*stack_a)->index >> shift) & 1;
		if (bit == 1)
			rotate_a(stack_a, print_list);
		else if (bit == 0)
		{
			if (stack_b == NULL)
			{
				init_stack_b(stack_a, &stack_b);
				ft_addback_print_lst(print_list, ft_newlist_print("pb"));
				continue ;
			}
			push_b(stack_a, &stack_b, print_list);
		}
	}
	push_back_a(stack_a, &stack_b, print_list, orig_size);
}

void	push_back_a(t_stack **stack_a, t_stack **stack_b,
	t_print_list **print_list, int orig_size)
{
	while ((*stack_a)->size != orig_size)
		push_a(stack_a, stack_b, print_list);
}

void	calculate_index(t_stack **stack_a)
{
	int		i;
	t_stack	*list;
	t_stack	*lst;

	list = *stack_a;
	while (list)
	{
		lst = *stack_a;
		i = 0;
		while (lst->next)
		{
			if (list->content > lst->next->content)
				i++;
			lst = lst->next;
		}
		list->index = i;
		list = list->next;
	}
}
