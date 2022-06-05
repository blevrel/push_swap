/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:20:01 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/29 12:15:01 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

char	**verify_args(char **list, int trigger)
{
	int			i;
	long long	*tab;
	int			size;

	i = 0;
	while (list[i])
		i++;
	size = i;
	tab = ft_calloc(sizeof(long long), i + 1);
	i = -1;
	while (list[++i])
	{
		if (ft_str_is_numeric(list[i]) == 1)
			return (free_list_if_error(list, tab, trigger));
		if (ft_strlen(list[i]) > 11)
			return (free_list_if_error(list, tab, trigger));
		tab[i] = ft_atol(list[i]);
		if (is_int(tab[i]) == 1)
			return (free_list_if_error(list, tab, trigger));
	}
	if (check_duplicate(tab, size) == 1)
		return (free_list_if_error(list, tab, trigger));
	return (list);
}

int	main(int argc, char **argv)
{
	char			**list;
	int				size;

	list = NULL;
	size = 0;
	if (argc < 2)
		return (1);
	if (argv[1][0] == '\0')
		ft_printf("Error\n");
	if (argc > 2)
		list = verify_args(&argv[1], 0);
	else if (ft_strlen(argv[1]) > 2)
		list = verify_args(ft_split(argv[1], ' '), 1);
	if (list == NULL)
		return (free_list(list));
	while (list[size])
		size++;
	if (size == 1)
		return (0);
	init_stack(list, size);
	if (argc == 2)
		return (free_list(list));
	return (0);
}

void	*free_list_if_error(char **list, long long *tab, int trigger)
{
	int	i;

	i = 0;
	if (list != NULL && trigger == 1)
	{
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	ft_printf("Error\n");
	free(tab);
	return (NULL);
}

int	free_list(char **list)
{
	int	i;

	i = 0;
	if (list != NULL)
	{
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	return (0);
}
