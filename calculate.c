/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:02:14 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:11:07 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_closest(t_list *list_a, t_list *list_b)
{
	int	curr_closest;

	list_b->closest = list_a->data;
	curr_closest = list_b->closest;
	while (list_a->next)
	{
		if (list_a->next && (ft_abs(curr_closest, list_b->data, '-')) \
		> (ft_abs(list_a->next->data, list_b->data, '-')))
		{
			list_b->closest = list_a->next->data;
			curr_closest = list_b->closest;
		}
		list_a = list_a->next;
	}
}

void	calculate_closest(t_list **stack_a, t_list **stack_b)
{
	t_list	*list_a;
	t_list	*list_b;

	list_b = *stack_b;
	if (!list_b)
		shutdown("Nothing to calculate, Stack b doesnt exist");
	while (list_b->next)
	{
		list_a = *stack_a;
		calc_closest(list_a, list_b);
		if (list_b->closest != 0 && list_a->next && \
			(ft_abs(list_a->data, list_b->data, '-')) \
			< (ft_abs(list_b->closest, list_b->data, '-')))
			list_b->closest = list_a->next->data;
		if (list_b->closest == 0 && list_a->next == NULL)
			list_b->closest = list_a->data;
		list_b = list_b->next;
	}
	list_a = *stack_a;
	calc_closest(list_a, list_b);
}
