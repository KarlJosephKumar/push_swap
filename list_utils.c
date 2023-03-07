/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:23:46 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/13 09:23:46 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newlst(int content)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	if (!l)
		return (0);
	l->data = content;
	l->index = 0;
	l->moves_a = 0;
	l->moves_b = 0;
	l->moves = 0;
	l->position = 0;
	l->closest = 0;
	l->half = 0;
	l->drot = 0;
	l->next = NULL;
	return (l);
}

void	ft_add_back(t_list **lst, int new_content)
{
	t_list	*new_node;
	t_list	*current;

	new_node = ft_newlst(new_content);
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
