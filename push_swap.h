/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:24:00 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/13 09:24:00 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct i_list
{
	int				position;
	int				index;
	int				data;
	int				closest;
	int				half;
	int				moves_a;
	int				moves_b;
	int				moves;
	int				drot;
	struct i_list	*next;
}	t_list;

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		args;
	int		args_a;
	int		args_b;
}	t_swap;

int		stack_creator_str(char *argv, t_swap *pswp);
int		stack_creator_arg(int argc, char **argv, t_swap *pswp);
void	free_split(char **split);
t_list	*ft_newlst(int content);
void	ft_add_back(t_list **lst, int new_content);
int		shutdown(char *str);
void	split_errors(char **sp, int i, int j);
void	argc_errors(char **argv);
void	check_same_num(t_list **stack1, t_list **stack2);
void	one_arg_error_check(char **sp, t_swap *pswp);
void	swap_a(t_list **stack_a, t_swap *pswp);
void	push_a(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	rot_a(t_list **stack_a, t_swap *pswp);
void	rev_rot_a(t_list **stack_a, t_swap *pswp);
void	swap_b(t_list **stack_b, t_swap *pswp);
void	push_b(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	rot_b(t_list **stack_b, t_swap *pswp);
void	rev_rot_b(t_list **stack_b, t_swap *pswp);
void	rot_a_b(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	rev_rot_a_b(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	swap_a_b(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	update_largs(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	update_pos_a(t_list **stack_a);
void	update_pos_b(t_list **stack_b);
void	update_pos(t_list **stack_a, t_list **stack_b);
void	calculate_closest(t_list **stack_a, t_list **stack_b);
int		lowest_moves_b(t_list **stack_b);
void	calculate_moves(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	is_over_half(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	is_over_half_b(t_list **stack_b, t_swap *pswp);
void	calc_doub_rot(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	index_args(t_list **stack_a, int args);
void	everything_to_b(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	sort_3(t_list **stack, t_swap *pswp);
void	sort_everything(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	last_sort(t_list **stack_a, t_swap *pswp);
void	execute_all_moves(t_list **stack_a, t_list **stack_b, t_swap *pswp);
void	choose_moves(t_list **st_a, t_list **st_b, \
t_swap *pswp, t_list *list_b);
t_list	*find_right_a(t_list **stack_a, t_list *list_b, int low_pos);
void	drot_moves(t_list **st_a, t_list **st_b, t_list *list_b, t_swap *pswp);
void	last_sort(t_list **stack_a, t_swap *pswp);
void	free_list(t_list **stack_a);
void	print_list(t_swap *pswp);
#endif