/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:17:46 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:11:04 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a, t_swap *pswp)
{
	t_list	*list;
	t_list	*head;
	t_list	*temp;

	if (pswp->args <= 1 || *stack_a == NULL)
		return ;
	list = *stack_a;
	head = pswp->stack_a;
	temp = pswp->stack_a->next;
	head->next = pswp->stack_a->next->next;
	temp->next = head;
	*stack_a = temp;
	update_pos_a(stack_a);
	ft_printf("sa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*temp;

	list_a = *stack_a;
	list_b = *stack_b;
	if (*stack_b == NULL)
	{
		*stack_b = list_a;
		temp = list_a->next;
		pswp->stack_b->next = NULL;
		*stack_a = temp;
		update_largs(stack_a, stack_b, pswp);
		ft_printf("pb\n");
		return ;
	}
	*stack_b = list_a;
	temp = list_a->next;
	pswp->stack_b->next = list_b;
	*stack_a = temp;
	update_largs(stack_a, stack_b, pswp);
	ft_printf("pb\n");
}

void	rot_a(t_list **stack_a, t_swap *pswp)
{
	t_list	*list;
	t_list	*head;
	t_list	*tail;
	int		i;

	i = 1;
	if (pswp->args_a <= 1 || *stack_a == NULL)
		return ;
	list = *stack_a;
	head = pswp->stack_a;
	tail = list->next;
	while (i < pswp->args_a)
	{
		list = list->next;
		i++;
	}
	list->next = head;
	head->next = NULL;
	*stack_a = tail;
	update_pos_a(stack_a);
}

void	rev_rot_a(t_list **stack_a, t_swap *pswp)
{
	t_list	*list;
	t_list	*tail;
	t_list	*head;
	int		i;

	i = 1;
	if (pswp->args <= 1 || *stack_a == NULL)
		return ;
	list = *stack_a;
	head = *stack_a;
	while (i < pswp->args_a - 1)
	{
		list = list->next;
		i++;
	}
	tail = list->next;
	tail->next = pswp->stack_a;
	list->next = NULL;
	*stack_a = tail;
	update_pos_a(stack_a);
}
