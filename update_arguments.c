/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:45:47 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:11:00 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_args_a(t_list **stack_a, t_swap *pswp)
{
	int		i;
	t_list	*list_a;

	i = 0;
	list_a = *stack_a;
	if (list_a == NULL)
	{
		pswp->args_a = i;
		return ;
	}
	i++;
	list_a->position = i;
	while (list_a->next != NULL)
	{
		list_a = list_a->next;
		i++;
		list_a->position = i;
	}
	pswp->args_a = i;
}

void	update_args_b(t_list **stack_b, t_swap *pswp)
{
	int		i;
	t_list	*list_b;

	i = 0;
	list_b = *stack_b;
	if (list_b == NULL)
	{
		pswp->args_b = i;
		return ;
	}
	i++;
	list_b->position = i;
	while (list_b->next != NULL)
	{
		list_b = list_b->next;
		i++;
		list_b->position = i;
	}
	pswp->args_b = i;
}

void	update_largs(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	update_args_a(stack_a, pswp);
	update_args_b(stack_b, pswp);
}

void	update_pos_a(t_list **stack_a)
{
	int		i;
	t_list	*list_a;

	i = 1;
	list_a = *stack_a;
	if (list_a == NULL)
		return ;
	list_a->position = i;
	i++;
	while (list_a->next != NULL)
	{			
		list_a = list_a->next;
		list_a->position = i;
		i++;
	}
}

void	update_pos_b(t_list **stack_b)
{
	int		i;
	t_list	*list_b;

	i = 1;
	list_b = *stack_b;
	if (list_b == NULL)
		return ;
	list_b->position = i;
	i++;
	while (list_b->next != NULL)
	{
		list_b = list_b->next;
		list_b->position = i;
		i++;
	}
}
