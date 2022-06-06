/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_manipulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:48:09 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/06 11:29:14 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_addback_print_lst(t_print_list **lst, t_print_list *new)
{
	t_print_list	*list;

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

t_print_list	*ft_newlist_print(char *content)
{
	t_print_list	*list;

	list = malloc(sizeof(t_print_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	display_print_list(t_print_list **print_list)
{
	t_print_list	*temp;
	t_print_list	*temp_next;

	temp = *print_list;
	*print_list = (*print_list)->next;
	free(temp);
	while (*print_list)
	{
		if (((*print_list)->next && ft_strncmp((*print_list)->content,
					(*print_list)->next->content, 4) == 1)
			|| ((*print_list)->next && ft_strncmp((*print_list)->content,
					(*print_list)->next->content, 4) == -1))
		{
			temp = *print_list;
			temp_next = (*print_list)->next;
			*print_list = (*print_list)->next->next;
			free(temp);
			free(temp_next);
			continue ;
		}
		ft_printf("%s\n", (*print_list)->content);
		temp = *print_list;
		*print_list = (*print_list)->next;
		free(temp);
	}
}

void	display_small_print_list(t_print_list **print_list)
{
	t_print_list	*temp;

	temp = *print_list;
	*print_list = (*print_list)->next;
	free(temp);
	while (*print_list)
	{
		ft_printf("%s\n", (*print_list)->content);
		temp = *print_list;
		*print_list = (*print_list)->next;
		free(temp);
	}
}
