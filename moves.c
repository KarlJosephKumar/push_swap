/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:14:48 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:25:13 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_double_or_not(t_list *list_a, t_list *list_b)
{
	if (list_a->half == list_b->half && \
	(list_b->moves_a > 0 && list_b->moves_b > 0))
	{
		if (list_b->moves_a > list_b->moves_b)
			list_b->moves = list_b->moves_a;
		else
			list_b->moves = list_b->moves_b;
	}
	else
		list_b->moves = list_b->moves_a + list_b->moves_b;
}

void	calc_total_moves(t_list **st_a, t_list **st_b)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *st_a;
	list_b = *st_b;
	while (list_b != NULL)
	{
		list_a = *st_a;
		while (list_a != NULL)
		{
			if (list_b->closest == list_a->data)
				calc_double_or_not(list_a, list_b);
			list_a = list_a->next;
		}
		list_b = list_b->next;
	}
}

void	calc_moves_a(t_list **stack_a, t_list *list_b, t_swap *pswp)
{
	t_list	*list_a;

	list_a = *stack_a;
	while (list_a != NULL)
	{
		list_b->moves_a = 0;
		if (list_b->closest == list_a->data && list_a->half == 0)
		{
			if (list_b->data > list_b->closest)
				list_b->moves_a++;
			list_b->moves_a += list_a->position - 1;
			return ;
		}
		else if (list_b->closest == list_a->data && list_a->half == 1)
		{
			if (list_b->data < list_b->closest)
				list_b->moves_a++;
			list_b->moves_a += pswp->args_a - list_a->position;
			return ;
		}
		list_a = list_a->next;
	}
}

void	calculate_moves(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = *stack_a;
	list_b = *stack_b;
	if (!list_b)
		shutdown("No stack b in calculate moves");
	while (list_b->next)
	{
		calc_moves_a(stack_a, list_b, pswp);
		if (list_b->half == 0)
			list_b->moves_b = list_b->position - 1;
		else
			list_b->moves_b = pswp->args_b - list_b->position + 1;
		list_b = list_b->next;
	}
	calc_moves_a(stack_a, list_b, pswp);
	if (list_b->position == 1)
		list_b->moves_b = pswp->args_b - list_b->position;
	else
		list_b->moves_b = pswp->args_b - list_b->position + 1;
	calc_total_moves(stack_a, stack_b);
}
