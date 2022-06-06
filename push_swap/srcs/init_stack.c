/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:00:42 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/06 14:42:33 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_stack(char **list, int size)
{
	t_stack			*stack;
	t_stack			*elem;
	int				i;

	i = 1;
	stack = ft_newlist(ft_atoi(list[0]), size);
	while (i < size)
	{
		elem = ft_newlist(ft_atoi(list[i]), size);
		ft_addback_lst(&stack, elem);
		i++;
	}
	if (size == 3 && is_sorted(&stack) != 1)
		sort_three(&stack);
	else if (size < 70)
		sort_small_list(&stack);
	else if (size >= 70)
	{
		calculate_index(&stack);
		sort_big_list(&stack);
	}
	free_linked_list(&stack);
}

void	free_linked_list(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}
