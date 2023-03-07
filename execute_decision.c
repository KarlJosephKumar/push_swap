/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_decision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:18:46 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:01:39 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_a_moves(t_list **st_a, t_list *list_a, t_swap *pswp)
{
	if (list_a->half == 0)
	{
		rot_a(st_a, pswp);
		ft_printf("ra\n");
	}
	else
	{
		rev_rot_a(st_a, pswp);
		ft_printf("rra\n");
	}
}

void	do_b_moves(t_list **st_b, t_list *list_b, t_swap *pswp)
{
	if (list_b->half == 0)
	{
		rot_b(st_b, pswp);
		ft_printf("rb\n");
	}
	else
	{
		rev_rot_b(st_b, pswp);
		ft_printf("rrb\n");
	}
}

void	choose_moves(t_list **st_a, t_list **st_b, t_swap *pswp, t_list *list_b)
{
	t_list	*list_a;
	int		low_pos;

	low_pos = lowest_moves_b(st_b);
	list_a = find_right_a(st_a, list_b, low_pos);
	while ((list_b->moves_a > 0 && list_b->moves_b > 0) && \
	(list_a->half == list_b->half))
	{
		if (list_a->half == 0 && list_b->half == 0)
			rot_a_b(st_a, st_b, pswp);
		else
			rev_rot_a_b(st_a, st_b, pswp);
		list_b->moves_a--;
		list_b->moves_b--;
	}
	while (list_b->moves_a != 0)
	{
		do_a_moves(st_a, list_a, pswp);
		list_b->moves_a--;
	}
	while (list_b->moves_b != 0)
	{
		do_b_moves(st_b, list_b, pswp);
		list_b->moves_b--;
	}
}
