/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:35:10 by kakumar           #+#    #+#             */
/*   Updated: 2023/03/06 15:25:48 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_errors(char **sp, int i, int j)
{
	if (j == 0 && (sp[i][j] == '-' || sp[i][j] == '+') && \
		(sp[i][j +1] < 48 || sp[i][j +1] > 57))
	{
		if (sp[i][j] == '-')
			shutdown("There has to be a number after minus");
		if (sp[i][j] == '+')
			shutdown("There has to be a number after plus");
	}
	if (sp[i][j] == '-' && (sp[i][j +1] < 48 || sp[i][j +1] > 57))
		shutdown("There has to be a number after minus");
	if (sp[i][j] == '+' && (sp[i][j +1] < 48 || sp[i][j +1] > 57))
		shutdown("There has to be a number after plus");
	if (j > 0 && (sp[i][j] == '+' || sp[i][j] == '-') && sp[i][j -1] != ' ')
		shutdown("No math equations in there mate");
	else
		return ;
}

void	argc_errors(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 48 && argv[i][j] <= 57) || \
			argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			else
				shutdown("Only integers plz");
		}
		i++;
	}
}

void	check_same_num(t_list **stack1, t_list **stack2)
{
	t_list	*temp;
	t_list	*temp2;
	int		num;

	if (!stack1 || !stack2)
		shutdown("No stack to check numbers in");
	temp = *stack1;
	while (temp->next)
	{
		num = temp->data;
		temp2 = *stack2;
		while (temp2->next)
		{
			if (temp->data == temp2->data && temp->index != temp2->index)
				shutdown("Cant have 2 of the same numbers");
			temp2 = temp2->next;
		}
		if (temp->data == temp2->data && temp->index != temp2->index)
			shutdown("Cant have 2 of the same numbers");
		temp = temp->next;
	}
}

void	one_arg_error_check(char **sp, t_swap *pswp)
{
	int	i;

	i = 0;
	pswp->stack_a = ft_newlst(ft_atoi_pswap(sp[i]));
	free(pswp->stack_a);
	free_split(sp);
	return ;
}
