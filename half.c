/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:06:43 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:25:39 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_over_half_b(t_list **stack_b, t_swap *pswp)
{
	t_list	*list_b;
	int		half_b;

	half_b = pswp->args_b / 2;
	list_b = *stack_b;
	while (list_b && list_b->next)
	{
		if (list_b->position != 1 && (list_b->position > half_b))
			list_b->half = 1;
		else
			list_b->half = 0;
		list_b = list_b->next;
	}
	if (list_b && list_b->position != 1 && list_b->position > half_b)
		list_b->half = 1;
	else if ((list_b && list_b->position < half_b) || list_b->position == 1)
		list_b->half = 0;
}

void	is_over_half(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	t_list	*list_a;
	int		half_a;

	list_a = *stack_a;
	half_a = pswp->args_a / 2;
	while (list_a && list_a->next)
	{
		if (list_a->position > half_a)
			list_a->half = 1;
		else
			list_a->half = 0;
		list_a = list_a->next;
	}
	if (list_a && list_a->position > half_a)
		list_a->half = 1;
	else if (list_a && list_a->position < half_a)
		list_a->half = 0;
	is_over_half_b(stack_b, pswp);
}
