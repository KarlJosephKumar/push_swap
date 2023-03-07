/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:07:41 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:25:59 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_pos(t_list **stack_a, t_list **stack_b)
{
	update_pos_a(stack_a);
	update_pos_b(stack_b);
}

void	everything_to_b(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	int		counter;

	counter = pswp->args - 3;
	while (counter > 0)
	{
		push_b(stack_a, stack_b, pswp);
		counter--;
	}
}

void	swap_a_b(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	swap_a(stack_a, pswp);
	swap_b(stack_b, pswp);
	ft_printf("ss\n");
}

void	rev_rot_a_b(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	rev_rot_a(stack_a, pswp);
	rev_rot_b(stack_b, pswp);
	ft_printf("rrr\n");
}

void	rot_a_b(t_list **stack_a, t_list **stack_b, t_swap *pswp)
{
	rot_a(stack_a, pswp);
	rot_b(stack_b, pswp);
	ft_printf("rr\n");
}
