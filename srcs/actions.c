/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:48:03 by mravily           #+#    #+#             */
/*   Updated: 2022/01/16 15:40:10 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap top two element in stack */
void	swap(t_element **stack, char *action)
{
	t_element	*tmp_first;
	t_element	*tmp_second;

	tmp_first = *stack;
	tmp_second = (*stack)->next;
	tmp_first->next = tmp_second->next;
	tmp_second->next = tmp_first;
	*stack = tmp_second;
	ft_putendl(action);
}

/* Push element from_stack to_stack and display action */
void	push(t_element **from_stack, t_element **to_stack, char *action)
{
	t_element	*tmp;

	if (*to_stack)
	{
		tmp = *from_stack;
		*from_stack = tmp->next;
		tmp->next = *to_stack;
		*to_stack = tmp;
	}
	else
	{
		tmp = *from_stack;
		*from_stack = tmp->next;
		*to_stack = tmp;
		(*to_stack)->next = NULL;
	}
	ft_putendl(action);
}

/* Top element goes to the bottom of the stack */
void	rotate(t_element **stack, char *action)
{
	t_element	*last;
	t_element	*tmp;

	last = ft_lstlast(*stack);
	tmp = *stack;
	last->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	ft_putendl(action);
}

/* Bottom element goes to the top of stack */
void	reverse_rotate(t_element **stack, char *action)
{
	t_element	*last;
	t_element	*second_last;
	t_element	*tmp;

	last = ft_lstlast(*stack);
	second_last = second_last_element(*stack, ft_lst_len(*stack));
	tmp = *stack;
	last->next = tmp;
	second_last->next = NULL;
	*stack = last;
	ft_putendl(action);
}

void	sort_list(t_list **data)
{
	int		len_stack;

	len_stack = ft_lst_len((*data)->stack_a);
	if (is_sorted((*data)->stack_a) == true)
		return ;
	if (len_stack == 2)
		swap(&(*data)->stack_a, "sa");
	else if (len_stack == 3)
		sort_three(data);
	else if (len_stack <= 5)
		sort_five(data, 5);
	else
		radix_sort_binary(data);
}
