/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:55:57 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:18:57 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_moves_b(t_list **stack_b)
{
	t_list	*list_b;
	int		low_moves_pos;
	int		low_moves;

	list_b = *stack_b;
	low_moves_pos = 0;
	low_moves = 2147483647;
	while (list_b != NULL)
	{
		if ((list_b->moves) < low_moves)
		{
			low_moves = list_b->moves;
			low_moves_pos = list_b->position;
		}
		list_b = list_b->next;
	}
	return (low_moves_pos);
}

void	sort_everything(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	t_list	*list_a;

	list_a = *stack_a;
	if (pswp->args == 2)
	{
		if (list_a->index > list_a->next->index)
		{
			rot_a(stack_a, pswp);
			ft_printf("ra\n");
		}
		return ;
	}
	if (pswp->args == 3)
	{
		sort_3(stack_a, pswp);
		return ;
	}
	everything_to_b(stack_a, stack_b, pswp);
	sort_3(stack_a, pswp);
	calculate_closest(stack_a, stack_b);
	is_over_half(stack_a, stack_b, pswp);
	calculate_moves(stack_a, stack_b, pswp);
	execute_all_moves(stack_a, stack_b, pswp);
}
