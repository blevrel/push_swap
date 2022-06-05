/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:52:57 by blevrel           #+#    #+#             */
/*   Updated: 2022/06/05 17:48:39 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				size;
	int				index;
}				t_stack;

typedef struct s_print_list
{
	const char				*content;
	struct s_print_list		*next;
}				t_print_list;

//push_swap.c
char			**verify_args(char **list, int trigger);
void			*free_list_if_error(char **list, long long *tab, int trigger);
int				free_list(char **list);

//check_errors.c
int				is_int(long long nb);
int				ft_str_is_numeric(char *str);
int				ft_duplicate_in_tab(long long *tab, long long nb, int size);
int				check_duplicate(long long *tab, int sze);

//init_stack.c
void			init_stack(char **list, int size);
void			free_linked_list(t_stack **lst);

//stack_manipulation.c
t_stack			*ft_newlist(int content, int size);
void			ft_addfront_lst(t_stack **lst, t_stack *new);
void			ft_addback_lst(t_stack **lst, t_stack *new);
int				ft_sizelst(t_stack *stack);

//print_list_manipulation.c
t_print_list	*ft_newlist_print(char *content);
void			ft_addback_print_lst(t_print_list **lst, t_print_list *new);
void			display_print_list(t_print_list **print_list);

//sort_list.c
void			ft_get_size(t_stack **stack);
void			bring_min_up(t_stack **stack, t_print_list **print_list);
void			sort_small_list(t_stack **stack_a);
void			sort_big_list(t_stack **stack_a);
void			init_stack_b(t_stack **stack_a, t_stack **stack_b);

//sort_big_list.c
void			compare_bytes(t_stack **stack_a, t_print_list **print_list,
					int shift);
void			push_back_a(t_stack **stack_a, t_stack **stack_b,
					t_print_list **print_list, int orig_size);
void			calculate_index(t_stack **stack_a);

//sorting_functions.c
void			swap_a(t_stack **stack, t_print_list **print_list);
void			swap_b(t_stack **stack, t_print_list **print_list);
void			push_a(t_stack **stack_a, t_stack **stack_b,
					t_print_list **print_list);
void			push_b(t_stack **stack_a, t_stack **stack_b,
					t_print_list **print_list);

//sorting_functions_2.c
void			rotate_a(t_stack **stack, t_print_list **print_list);
void			rotate_b(t_stack **stack, t_print_list **print_list);
void			reverse_rotate_a(t_stack **stack, t_print_list **print_list);
void			reverse_rotate_b(t_stack **stack, t_print_list **print_list);

//sorting_functions_3.c
void			ss(t_stack **stack_a, t_stack **stack_b,
					t_print_list **print_list);
void			rr(t_stack **stack_a, t_stack **stack_b,
					t_print_list **print_list);
void			rrr(t_stack **stack_a, t_stack **stack_b,
					t_print_list **print_list);

//is_sorted.c
int				is_sorted(t_stack **stack);

#endif
