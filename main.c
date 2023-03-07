/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:23:53 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/13 09:23:53 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shutdown(char *str)
{
	(void) str;
	write(2, "Error\n", 6);
	exit(0);
}

void	free_list(t_list **stack_a)
{
	t_list	*list_a;
	t_list	*temp;

	list_a = *stack_a;
	while (list_a->next != NULL)
	{
		temp = list_a->next;
		free(list_a);
		list_a = temp;
	}
	free(list_a);
}

int	check_if_sorted(t_list **stack_a)
{
	t_list	*list_a;

	list_a = *stack_a;
	while (list_a->next)
	{
		if ((list_a->index + 1) == list_a->next->index)
			list_a = list_a->next;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_swap	pswp;

	if (argc < 2)
		return (0);
	pswp.stack_a = NULL;
	pswp.stack_b = NULL;
	if (argc == 2)
		stack_creator_str(argv[1], &pswp);
	if (argc > 2)
		stack_creator_arg(argc, argv, &pswp);
	if (pswp.args <= 1)
		return (0);
	if (check_if_sorted(&pswp.stack_a) == 0)
	{
		free_list(&pswp.stack_a);
		return (0);
	}
	update_largs(&pswp.stack_a, &pswp.stack_b, &pswp);
	sort_everything(&pswp.stack_a, &pswp.stack_b, &pswp);
	free_list(&pswp.stack_a);
	return (0);
}
