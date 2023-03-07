/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:04:47 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:21:35 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_big_to_small(t_list **stack, t_swap *pswp)
{
	t_list	*list;

	list = *stack;
	if (list->next->data < list->next->next->data)
	{
		rot_a(stack, pswp);
		ft_printf("ra\n");
		return ;
	}
	rot_a(stack, pswp);
	ft_printf("ra\n");
	swap_a(stack, pswp);
}

void	sort_3_small_to_big(t_list **stack, t_swap *pswp, t_list *list)
{
	if (list->next->data < list->next->next->data)
		return ;
	rev_rot_a(stack, pswp);
	ft_printf("rra\n");
	swap_a(stack, pswp);
	return ;
}

void	sort_3(t_list **stack, t_swap *pswp)
{
	t_list	*list;

	list = *stack;
	if (list->data > list->next->data && list->data > list->next->next->data)
	{
		sort_3_big_to_small(stack, pswp);
		return ;
	}
	else if (list->data < list->next->data \
	&& list->data < list->next->next->data)
		sort_3_small_to_big(stack, pswp, list);
	if (list->data > list->next->data && list->data < list->next->next->data)
	{
		swap_a(stack, pswp);
		return ;
	}
	else
	{
		rev_rot_a(stack, pswp);
		ft_printf("rra\n");
	}
}

void	choose_sort_way(t_list *list_a, t_list **stack_a, t_swap *pswp)
{
	int	moves;

	moves = 0;
	if (list_a->position > (pswp->args / 2))
	{
		moves = pswp->args - list_a->position + 1;
		while (moves-- > 0)
		{
			rev_rot_a(stack_a, pswp);
			ft_printf("rra\n");
		}
	}
	else
	{
		moves = list_a->position -1;
		while (moves-- > 0)
		{
			rot_a(stack_a, pswp);
			ft_printf("ra\n");
		}
	}
}

void	last_sort(t_list **stack_a, t_swap *pswp)
{
	t_list	*list_a;

	list_a = *stack_a;
	while (list_a != NULL)
	{
		if (list_a->index == 1)
		{
			choose_sort_way(list_a, stack_a, pswp);
			return ;
		}
		list_a = list_a->next;
	}
}
