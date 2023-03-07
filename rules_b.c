/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:16:19 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:11:04 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **stack_b, t_swap *pswp)
{
	t_list	*list;
	t_list	*head;
	t_list	*temp;

	if (pswp->args <= 1 || *stack_b == NULL)
		return ;
	list = *stack_b;
	head = pswp->stack_b;
	temp = pswp->stack_b->next;
	head->next = pswp->stack_b->next->next;
	temp->next = head;
	*stack_b = temp;
	update_pos_b(stack_b);
	ft_printf("sb\n");
}

void	push_a(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*temp;

	list_a = *stack_a;
	list_b = *stack_b;
	*stack_a = list_b;
	temp = list_b->next;
	*stack_b = temp;
	pswp->stack_a->next = list_a;
	update_largs(stack_a, stack_b, pswp);
	ft_printf("pa\n");
}

void	rot_b(t_list **stack_b, t_swap *pswp)
{
	t_list	*list;
	t_list	*head;
	t_list	*tail;
	int		i;

	i = 1;
	if (pswp->args_b <= 1 || *stack_b == NULL)
		return ;
	list = *stack_b;
	head = pswp->stack_b;
	tail = list->next;
	while (i < pswp->args_b)
	{
		list = list->next;
		i++;
	}
	list->next = head;
	head->next = NULL;
	*stack_b = tail;
	update_pos_b(stack_b);
}

void	rev_rot_b(t_list **stack_b, t_swap *pswp)
{
	t_list	*list;
	t_list	*tail;
	int		i;

	i = 1;
	if (pswp->args_b <= 1 || *stack_b == NULL)
		return ;
	list = *stack_b;
	while (i < pswp->args_b -1)
	{
		list = list->next;
		i++;
	}
	tail = list->next;
	tail->next = pswp->stack_b;
	list->next = NULL;
	*stack_b = tail;
	update_pos_b(stack_b);
}
