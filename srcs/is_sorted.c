/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:01:50 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/05 18:29:19 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*list;

	if ((*stack)->size == 1)
		return (1);
	list = *stack;
	while (list->next)
	{
		if (list->content < list->next->content)
		{
			list = list->next;
			continue ;
		}
		return (0);
	}
	return (1);
}
