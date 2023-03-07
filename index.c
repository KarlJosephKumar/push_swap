/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:45:17 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:25:27 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_indexes(t_list **stack_a, int smallest, int index)
{
	t_list	*list;
	int		i;

	i = index;
	list = *stack_a;
	while (list->next)
	{
		if (list->data == smallest && list->index == 0)
		{
			list->index = i;
			return ;
		}
		else
			list = list->next;
	}
	if (list->data == smallest)
			list->index = i;
}

void	index_args(t_list **stack_a, int args)
{
	int		i;
	t_list	*list;
	int		smallest;

	list = *stack_a;
	i = 1;
	while (args > 0)
	{
		list = *stack_a;
		smallest = 2147483647;
		while (list->next != NULL)
		{
			if (list->data < smallest && list->index == 0)
				smallest = list->data;
			list = list->next;
		}
		if (list->data < smallest && list->index == 0)
			smallest = list->data;
		add_indexes(stack_a, smallest, i);
		i++;
		args--;
	}
}
