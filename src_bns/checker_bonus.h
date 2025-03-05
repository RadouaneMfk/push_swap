/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:43:19 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/04 11:59:26 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../lib/libft.h"
# include "GNL/get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				indice;
	struct s_stack	*next;
}	t_stack;

void	free_s(char **s);
void	check_duplicate(long *arr, int count);
void	malloc_arr(int ac, char **str, char **result, long **numbers);
void	add_to_stack(t_stack **stack, int value);
void	check_sign(char **result, int *j, int *k, long *numbers);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack	**stack);
void	ra(t_stack	**a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rot(t_stack	**stack);
void	rra(t_stack	**stack);
void	rrb(t_stack	**b);
void	rrr(t_stack	**a, t_stack **b);
void	sort_three(t_stack	**stack);
void	sort_four(t_stack **stack_a, t_stack	**stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	find_min(t_stack **head, t_stack **min, int *i, int *k);
void	set_indices(t_stack **stack);
int		stack_size(t_stack *stack);
void	range_sort(t_stack **a, t_stack **b);
void	back_to_a(t_stack **a, t_stack **b);
int		max_indice(t_stack *stack);
void	sort(t_stack **a, t_stack **b);
void	parse_input(int ac,	char **str, t_stack **stack_a);
void	read_move(char **move, t_stack **a, t_stack **b);
#endif