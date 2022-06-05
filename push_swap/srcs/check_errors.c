/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:53:55 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/26 13:17:44 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_int(long long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && (str[i + 1] > '0' && str[i] < '9'))
		{
			i++;
			continue ;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicate(long long *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_duplicate_in_tab(tab, tab[i], size) == 1)
			return (1);
		i++;
	}
	free(tab);
	return (0);
}

int	ft_duplicate_in_tab(long long *tab, long long nb, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i] == nb)
			j++;
		i++;
	}
	if (j != 1)
		return (1);
	return (0);
}
