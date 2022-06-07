/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:28:18 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/05 10:10:06 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_sizelst(t_stack *stack)
{
	t_stack	*list;
	int		i;

	list = stack;
	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	ft_addfront_lst(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_newlist(int content, int size)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->size = size;
	list->next = NULL;
	list->index = 0;
	return (list);
}

void	ft_addback_lst(t_stack **lst, t_stack *new)
{
	t_stack	*list;

	if (*lst)
	{
		list = *lst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
	}
	else
		*lst = new;
}
