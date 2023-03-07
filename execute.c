/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:18:20 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:04:32 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recalc_everything(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	update_largs(stack_a, stack_b, pswp);
	is_over_half(stack_a, stack_b, pswp);
	calculate_closest(stack_a, stack_b);
	calculate_moves(stack_a, stack_b, pswp);
}

t_list	*find_right_a(t_list **stack_a, t_list *list_b, int low_pos)
{
	t_list	*list_a;

	list_a = *stack_a;
	while (list_a->next)
	{
		while (list_b->position != low_pos)
			list_b = list_b->next;
		if (list_a->data == list_b->closest)
			break ;
		list_a = list_a->next;
	}
	return (list_a);
}

void	exec_moves(t_list **st_a, t_list **st_b, t_swap *pswp)
{
	t_list	*list_b;
	int		low_pos;
	t_list	*list_a;

	list_b = *st_b;
	low_pos = lowest_moves_b(st_b);
	list_a = find_right_a(st_a, list_b, low_pos);
	while (list_b != NULL)
	{
		if (low_pos == list_b->position)
		{
			choose_moves(st_a, st_b, pswp, list_b);
			if (list_b->moves_b == 0)
				push_a(st_a, st_b, pswp);
			return ;
		}
		list_b = list_b->next;
	}
}

void	execute_all_moves(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *stack_a;
	list_b = *stack_b;
	while (list_b->next)
	{
		exec_moves(stack_a, stack_b, pswp);
		recalc_everything(stack_a, stack_b, pswp);
		list_b = *stack_b;
	}
	exec_moves(stack_a, stack_b, pswp);
	last_sort(stack_a, pswp);
}
