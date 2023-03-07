/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:23:42 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/13 09:23:42 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	get_arg_count(char **sp, t_swap *pswp, int i, int j)
{
	i = 0;
	while (sp[i])
	{
		j = 0;
		while (sp[i][j])
		{
			if ((sp[i][j] >= 48 && sp[i][j] <= 57) || \
			sp[i][j] == '-' || sp[i][j] == '+')
			{
				split_errors(sp, i, j);
				j++;
			}
			else
				shutdown("A non integer has appeared.");
		}
		i++;
	}
	pswp->args = i;
	pswp->args_a = i;
	if (pswp->args == 1)
	{
		one_arg_error_check(sp, pswp);
		return ;
	}
}

int	stack_creator_str(char *argv, t_swap *pswp)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(argv, ' ');
	if (!split)
		shutdown("Error in creating stack | split");
	get_arg_count(split, pswp, 0, 0);
	if (pswp->args < 1)
	{
		free_split(split);
		return (0);
	}
	else if (pswp->args == 1)
		return (0);
	if (pswp->args > 1)
		pswp->stack_a = ft_newlst(ft_atoi_pswap(split[i]));
	i++;
	while (split[i])
		ft_add_back(&pswp->stack_a, ft_atoi_pswap(split[i++]));
	free_split(split);
	index_args(&pswp->stack_a, pswp->args);
	check_same_num(&pswp->stack_a, &pswp->stack_a);
	return (0);
}

int	stack_creator_arg(int argc, char **argv, t_swap *pswp)
{
	int	i;

	i = 1;
	pswp->args = argc - 1;
	pswp->args_a = argc - 1;
	argc_errors(argv);
	pswp->stack_a = ft_newlst(ft_atoi_pswap(argv[i]));
	i++;
	while (i < argc)
	{
		ft_add_back(&pswp->stack_a, ft_atoi_pswap(argv[i]));
		i++;
	}
	if (pswp->args == 1)
		return (0);
	index_args(&pswp->stack_a, pswp->args);
	check_same_num(&pswp->stack_a, &pswp->stack_a);
	return (0);
}
